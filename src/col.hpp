class ColBase
{
public:
  virtual void print_values(){};
  virtual void add_value(string val){};
  virtual void get_value(int i){};
  //virtual void get_values(){};
};


class ColInt : public ColBase
{

public:
  vector<int> values;

  ColInt() {}

  vector<int> get_values() { return values; }

  void get_value(int i) { cout << values[i]; }

  void add_value(string val) { values.push_back(stoi(val)); }

  void print_values()
  {
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
};

class ColFloat : public ColBase
{

public:
  vector<float> values;

  ColFloat() {}

  vector<float> get_values() { return values; }

  void get_value(int i) { cout << values[i]; }

  void add_value(string val) { values.push_back(stof(val)); }

  void print_values()
  {
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
};

class ColChar : public ColBase
{

public:
  int m_length;
  vector<char *> values;

  ColChar(int length) { m_length = length; }

  vector<char *> get_values() { return values; }

  void get_value(int i) { cout << values[i]; }

  void add_value(string val) { 
    char* temp =(char*)malloc(sizeof(char) * m_length);
    strcpy(temp,val.c_str());
    values.push_back(temp); 
    }

  void print_values()
  {
    for (int i = 0; i < values.size(); i++)
    {
      cout << values[i] << endl;
    }
  }
};