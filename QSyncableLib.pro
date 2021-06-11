QT -= gui
QT += qml quick

TEMPLATE = lib
# CONFIG += staticlib

DEFINES += LIBQSYNCABLE_LIBRARY


CONFIG += c++11

include(qsyncable.pri)

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

#HEADERS += \
#    LibQSyncable_global.h
