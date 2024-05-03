#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int UNDEF_SENTENCE=0;
const int NORMAL_SENTENCE=1;
const int INTERROGATIVE_SENTENCE=2;
const int IMPERATIVE_SENTENCE=3;

class Sentence {
  public :
    Sentence() { data_ = ""; type_ = UNDEF_SENTENCE;}

    int GetType() { return type_; }
    string GetString() { return data_; }

    void SetSentenceData(string s) { 
      SetSenteceType(s);
      data_ = s; 
    }

  protected :
    void SetSenteceType(string s) {
      // -- ���� ������ �Ǵ��Ͽ� type_�� ����, default�� �򼭹�
      type_ = NORMAL_SENTENCE;
    }

  private :
    string data_;
    int type_;
};

class Manual {
  public :
    string GetContents() { return contents_; }
    void AddContents(string s) { contents_ += s; }

  private : 
    string contents_;
};

class Translator {
  public :
    Manual GetResult() { return result_; }

    virtual void TransNormalSentence(string s)=0;
    virtual void TransInterrogativeSentence(string s)=0;
    virtual void TransImperativeSentence(string s)=0;

  protected :
    Manual result_;
};

class EnglishTranslator : public Translator {
  public : 
    void TransNormalSentence(string s)
    {
      string output;
      // -- s�� ����� ����
      result_.AddContents(output);
    }

    void TransInterrogativeSentence(string s)
    {
      string output;
      // -- s�� ����� ����
      result_.AddContents(output);
    }

    void TransImperativeSentence(string s)
    {
      string output;
      // -- s�� ����� ����
      result_.AddContents(output);
    }
};

class JapaneseTranslator : public Translator {
  public : 
    void TransNormalSentence(string s)
    {
      string output;
      // -- s�� �Ͼ�� ����
      result_.AddContents(output);
    }

    void TransInterrogativeSentence(string s)
    {
      string output;
      // -- s�� �Ͼ�� ����
      result_.AddContents(output);
    }

    void TransImperativeSentence(string s)
    {
      string output;
      // -- s�� �Ͼ�� ����
      result_.AddContents(output);
    }
};

class FrenchTranslator : public Translator {
  public : 
    void TransNormalSentence(string s)
    {
      string output;
      // -- s�� ��������� ����
      result_.AddContents(output);
    }

    void TransInterrogativeSentence(string s)
    {
      string output;
      // -- s�� ��������� ����
      result_.AddContents(output);
    }

    void TransImperativeSentence(string s)
    {
      string output;
      // -- s�� ��������� ����
      result_.AddContents(output);
    }
};

class Director {
  public : 
    void DoTranslate(char* pInFile, Translator& t)
    {
      ifstream ifs(pInFile);
      if (!ifs) {
        cout << "Can't Open File : " << pInFile << endl;
        return;
      }

      Sentence next;
      while (!(next=GetSentence(ifs)).GetString().empty()) {
        switch (next.GetType()) {
          case NORMAL_SENTENCE : // -- �򼭹�
            t.TransNormalSentence(next.GetString());
            break;
          case INTERROGATIVE_SENTENCE : // -- �ǹ���
            t.TransInterrogativeSentence(next.GetString());
            break;
          case IMPERATIVE_SENTENCE : // -- ���ɹ�
            t.TransImperativeSentence(next.GetString());
            break;
          default :
            cout << "Untranslatable sentence type" << endl;
            return;
        }
      }
    }

  protected:
    Sentence GetSentence(ifstream& ifs) 
    {
      int c;
      string s;
      Sentence sentence;
      while ((c=ifs.get()) != EOF) {
        s += c;
        if (c == '?' || c == '.') 
          break;
      }
      sentence.SetSentenceData(s);
      return sentence;
    }
};

int main()
{
  Director d;
  EnglishTranslator t;
  d.DoTranslate("input.txt", t);

  Manual out = t.GetResult();
  cout << out.GetContents() << endl;
}