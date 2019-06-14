#include "interface.h"

HTTP_Interface::HTTP_Interface(QObject *parent)
	: QObject(parent), m_pManager(new QNetworkAccessManager)
{

}

HTTP_Interface::~HTTP_Interface()
{

}

QByteArray HTTP_Interface::getMD5(QByteArray ba) {
	QByteArray bb;
	QCryptographicHash md(QCryptographicHash::Md5);
	md.addData(ba);
	bb = md.result();
	return bb.toHex();
}



QNetworkAccessManager* HTTP_Interface::sendPost(QByteArray sendBuf, QUrl url, int port/* =13579 */, QString contentType/* = QString("application/json") */) {
	//url = QUrl("http://127.0.0.1:6789/predict");
	//url.setPort(port);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant(contentType));
	m_pManager->post(request, sendBuf);
	return m_pManager;
}

QString HTTP_Interface::UnicodeToString(QByteArray array) {
	QString str(array);
	do {
		int idx = str.indexOf("\\u");
		QString strHex = str.mid(idx, 6);
		strHex = strHex.replace("\\u", QString());
		int nHex = strHex.toInt(0, 16);
		str.replace(idx, 6, QChar(nHex));
	} while (str.indexOf("\\u") != -1);
	return str;
}