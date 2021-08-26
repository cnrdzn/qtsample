#include "settings.h"

#include <QQmlApplicationEngine>
#include <QDebug>
#include <QGuiApplication>
#include <QIcon>

Settings::Settings(QObject* parent) :
  QSettings(parent) {

}

Settings::~Settings() {

}
Settings::Settings(QQmlEngine *engine)
{
    _translator = new QTranslator(this);
    _engine = engine;
}

QVariant Settings::value(const QString &key, const QVariant &defaultValue = QVariant()) {

    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, orgName, appName);

    return QSettings::value(key, defaultValue);

}

bool Settings::boolValue(const QString &key, bool defaultValue) {
  return QSettings::value(key, defaultValue).toBool();
}

void Settings::setValue(const QString &key, const QVariant &value) {
qDebug() << "xxx";
  QSettings::setValue(key, value);
  emit settingChanged(key);
}

void Settings::setValueIfNotSet(const QString &key, const QVariant &value) {

  if( !QSettings::contains(key) ) {
    QSettings::setValue(key, value);
    emit settingChanged(key);
  }
}

void Settings::initToDefaults() {
  setValueIfNotSet("test", true);
}

void Settings::getValue(QString whatis)
{
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, orgName, appName);

    QString valueOfData = "cnr design";
    settings.value(whatis);

}

void Settings::selectLanguage(QString language)
{

    if (!_translator->load(QString("translating-qml_%1").arg(language), QString(":/resources/i18n/")  )
            )
    {
        qDebug() << "bip";
    }

    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, orgName, appName);

    settings.setValue("userlang", language);
    settings.sync();

    qApp->installTranslator(_translator);
    _engine->retranslate();

    emit languageChanged();

}
void Settings::setAppInfo() {

    QGuiApplication::setOrganizationName(orgName);
    QGuiApplication::setOrganizationDomain(orgDomain);
    QGuiApplication::setApplicationName(appName);

    QGuiApplication::setWindowIcon(QIcon("://resources/images/appicon.ico"));

    QQmlApplicationEngine engine;
    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, orgName, appName);
    selectLanguage(settings.value("userlang").toString());

}
