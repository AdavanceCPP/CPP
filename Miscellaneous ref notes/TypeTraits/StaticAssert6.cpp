#include <iostream> 
using namespace std; 

template <class T, int length> 
class Packet
{         
  static_assert (length > 128, "packet size is shorter!");  //  static assert on length 
private:       
    T m_datapacket [length]; 
};    


int main() 
{     
   Packet <int, 132> TCPip; // This is OK as static check will    pass.     
   //Packet <int, 2> FTP; // This is not OK as static check will not pass.       
   return 0; 
}