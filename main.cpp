#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

        db.setHostName("localhost");  // 假定数据库在本机

        db.setDatabaseName("test"); // 打开数据库名

        db.setUserName("testuser");  // 数据库用户名

        db.setPassword("12345678");  // 数据库密码

        if (!db.open())

            qDebug() << "Failed to connect to root mysql!";

        else qDebug() << "open success!";



        QSqlQuery query(db);


        //创建表stu，id为主键，注意这里varchar一定要指定长度

        query.exec("create table stu(id int primary key,score int ,name varchar(20))");



       // 向表中插入3条记录，注意字符串是单引号

        query.exec("insert into stu values(1,80,'zhangsan')");

        query.exec("insert into stu values(2,90,'lisi')");

        query.exec("insert into stu values(3,70,'wangwu')");





       // 查询

        query.exec("select * from stu where score >= 75");

        while(query.next())

        {

            int value0 = query.value(0).toInt();

    int value1 = query.value(1).toInt();

            QString value2 = query.value(2).toString();

            qDebug() << value0 << value1<<value2;

        }

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
