#pragma once

#include <string>
#include <filesystem>

std::tr2::sys::path tmpPath;


class CProductionlineLog
{
public:
	static CProductionlineLog& GetInstance();

	void WriteLog(std::string strfilekey, std::string strContext, bool bWrite = false);
	void ClearContext() {
		m_strContext.clear();
	}

	void GetFileOKNGNUM(int& nOk, int& nALL, std::string qstrTime) {
		int npass = 0;
		int nAll = 0;
		std::string qstr = QDir::currentPath();
		std::string qfilepath = qstr + "/RbtDevLogs/" + m_strDevname + "_" + qstrTime + ".Log";
		QFileInfo fileinfo(qfilepath);
		if (fileinfo.exists()) {
			QFile f(qfilepath);
			if (!f.open(QIODevice::Text | QIODevice::ReadOnly))
				QMessageBox::information(nullptr, "error", "error : open file failed");
			else {
				while (!f.atEnd())
				{
					QByteArray line = f.readLine();
					QString strtmp(line);
					if (strtmp.indexOf("NG") != -1) {
						nAll++;
					}
					else if (strtmp.indexOf("OK") != -1) {
						npass++;
						nAll++;
					}
				}
			}
			f.close();
		}
		nOk = npass;
		nALL = nAll;
	}
	void GetFilesOKNGNUM(int &nOK, int& nALL);

protected:
	CProductionlineLog() {
		// 检查 创建exe路径下是否存在目录
		CreateLogDir();
	};

	~CProductionlineLog() {
		QFile* pQfile = nullptr;
		auto iter = m_mapDevlogs.begin();
		while (iter != m_mapDevlogs.end())
		{
			pQfile = iter->second;
			pQfile->close();
			delete pQfile;
			iter++;
		}
	}

	void CreateLogDir();

	QString						m_strDevname;
	std::map<QString, QFile*>	m_mapDevlogs;
	ST_LOGINFO					m_logInfo;
	QString						m_strContext;
};