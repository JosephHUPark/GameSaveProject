#include "mysql.h"

mysql::mysql() {
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("gamesavedb");
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }
}

mysql::~mysql() {}


void mysql::save_data(int mode, int x, int y, int time) {
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("CALL PQ_SAVE_DATA(?,?,?,?)");
    pstmt->setInt(1, mode);
    pstmt->setInt(2, x);
    pstmt->setInt(3, y);
    pstmt->setInt(4, time);
    pstmt->executeUpdate();
    delete pstmt;
    mysql();
}

void mysql::load_data(int& mode, int& x, int& y, int& time) {
    sql::PreparedStatement* pstmt = con->prepareStatement("CALL PQ_LOAD_DATA()");
    pstmt->execute();
    sql::ResultSet* rset = pstmt->getResultSet();
    while (rset->next()) {
        mode = rset->getInt(1);
        x = rset->getInt(2);
        y = rset->getInt(3);
        time = rset->getInt(4);
        std::cout << mode << std::endl;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << time << std::endl;
    }
    delete pstmt;
    mysql();
}