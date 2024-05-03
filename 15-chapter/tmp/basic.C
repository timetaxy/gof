#include <iostream>
#include <string>
using namespace std;

class User {
  public :
    int userNo_;
    string userId_;
    string userName_;
};

class Member {
  public :
    void List(int pageNo, int sortType) {
      // -- sortType 별로 Sorting 된 회원 목록 페이지 표시
    }
    void Join(User& aUser) {
      // -- aUser를 회원으로 승인
    }
    void Withdraw(User& aUser) {
      // -- aUser를 회원에서 삭제
    }
    void JoinApply(User& aUser) {
      // -- 회원 등록 신청
    }
    void ApplyList(int pageNo, int sortType) {
      // -- 회원 등록 신청한 이용자 목록 표시
    }
};

class BBS {
  pubilc : 
    virtual void List(int pageNo) = 0;
    virtual void Read(int bbsNo) = 0;
    virtual void Write() = 0;
    virtual void Remove(int bbsNo) = 0;
};

class FreeBBS : public BBS {
  public : 
    void List(int pageNo) {
      // -- pageNo 위치의 게시물 리스트를 보여준다.
    }
    void Read(int bbsNo) {
    }
    void Write() {
    }
    void Remove(int bbsNo) {
    }
};
