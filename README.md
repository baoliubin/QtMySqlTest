# QtMySqlTest
Qt使用MySql的Demo

## 开发环境 
1.ubuntu 16.04.5

2.Qt5.12.3

3.mysql-client、mysql-server
（5.7）

## Qt在Ubuntu下的MySql驱动编译安装
1.进入QT安装目录的源码目录（如果安装 时没有选择源码，重新安装下），找到MySql驱动源码目录 
如：
~/Qt5.12.3/5.12.3/Src/qtbase/src/plugins/sqldrivers/mysql 

2.执行如下指令，进行驱动编译：
~/Qt5.12.3/5.12.3/gcc_64/bin/qmake "INCLUDEPATH+=/usr/include/mysql" "LIBS+=-L/usr/lib/x86_64-linux-gnu/ -lmysqlclient" mysql.pro

注：如果出错： 
Project ERROR: Library ‘mysql’ is not defined. 
则打开mysql.pro文件注释掉QMAKE_USE +=mysql这行 
如果出错： 
qtsqldrivers-config.pri没找到

将` ~/Qt5.12.3/5.12.3/Src/qtbase/src/plugins/sqldrivers/qsqldriverbase.pri进行修改如下`
`
QT  = core core-private sql-private

# For QMAKE_USE in the parent projects.
#include($$shadowed($$PWD)/qtsqldrivers-config.pri)
include($$shadowed($$PWD)/configure.pri)

PLUGIN_TYPE = sqldrivers
load(qt_plugin)

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII
`
3.执行:

`make`

4.拷贝生成的so文件至对应目录
`cp ~/Qt5.12.3/5.12.3/Src/qtbase/src/plugins/sqldrivers/plugins/sqldrivers/libqsqlmysql.so ~/Qt5.12.3/5.12.3/gcc_64/plugins/sqldrivers/`

5.完成
