#include <stdio.h>

class DBQuery{
private:
    static int hCon;
    int nResult;
public:
    DBQuery() { };
    static void DBConnect(const char *Server, const char *ID, const char *SQL);
    static void DBDisConnect();
    bool RunQuery(const char *SQL);
};
int DBQuery::hCon;

void DBQuery::DBConnect(const char *Server, const char *ID, const char *SQL){
    // DB 서버 접속 문
    hCon = 1234;
    puts("연결 되었습니다.\n");
}
void DBQuery::DBDisConnect(){
    // 접속 해제
    hCon = NULL;
    puts("연결이 끊어졌습니다.\n");
}
bool DBQuery::RunQuery(const char *SQL){
    //Query(hCon, SQL);
    puts(SQL);
    return true;
}

int main(){
    DBQuery::DBConnect("Secret", "Adult", "doemfdmsrkf");
    DBQuery Q1, Q2, Q3;

    Q1.RunQuery("select * from tblBuja where 나랑 친한");

    DBQuery::DBDisConnect();

    return 0;
}