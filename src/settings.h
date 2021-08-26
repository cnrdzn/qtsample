#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QTranslator>
#include <QSettings>
#include <QQmlEngine>

class Settings : public QSettings {
  Q_OBJECT
public:
  Settings(QObject *parent = 0);
  virtual ~Settings();

  QString valueOfData = "cnr design";

  QString orgName = "cnr design";
  QString orgDomain = "cnr.design";
  QString appName = "QML Testing App";

  Q_INVOKABLE
  void selectLanguage(QString language);

  Q_INVOKABLE
  void setValue(const QString &key, const QVariant &value);

  Q_INVOKABLE
  void setValueIfNotSet(const QString &key, const QVariant &value);

  Q_INVOKABLE
  QVariant value(const QString &key, const QVariant &defaultValue);

  Q_INVOKABLE
  bool boolValue(const QString &key, const bool defaultValue);

  Q_INVOKABLE
  void initToDefaults();

  Q_INVOKABLE
  void getValue(QString whatis);

  Q_INVOKABLE
  void setAppInfo();

  Settings(QQmlEngine *engine);

  //QString getEmptyString();



signals:
  void settingChanged(const QString& key);
  void languageChanged();
private:
    QTranslator *_translator;
    QQmlEngine *_engine;
};

#endif // SETTINGS_H
