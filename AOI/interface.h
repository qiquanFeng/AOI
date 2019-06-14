#ifndef NETFACE_H
#define NETFACE_H

#include <QObject>
#include <QCryptographicHash>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class HTTP_Interface : public QObject
{
	Q_OBJECT

public:
	HTTP_Interface(QObject *parent=0);
	~HTTP_Interface();

	QNetworkAccessManager *m_pManager;

	QNetworkAccessManager* sendPost(QByteArray sendBuf,QUrl url,int port=13579, QString contentType = QString("application/json"));
	static QString UnicodeToString(QByteArray array);//JsonÖÐÎÄ×ª»»
	static QByteArray getMD5(QByteArray sourceArray);

private:
	
};

#endif // NETFACE_H
