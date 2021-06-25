#include <iostream>

struct AdList{
    public: int** cl2p_Ptr;
    public: char* cp_Name;
    public: int i_Size;

    public: AdList(char* cp_Name, int i_Size){
        cl2p_Ptr= new int*[i_Size];
        for(int i_Ct=0; i_Ct< i_Size; i_Ct++){
            cl2p_Ptr[i_Ct] = new int[i_Size]{};
        }
        this->cp_Name = cp_Name;
        this->i_Size = i_Size;
    }

    public: bool fn_InsVet(char c_NameA, char c_NameB){
        int i_RInd = -1;
        int i_CInd = -1;
        for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
            if(c_NameA == cp_Name[i_Ct]){
                i_RInd = i_Ct;
                break;
            }
        }
        for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
            if(c_NameB == cp_Name[i_Ct]){
                i_CInd = i_Ct;
                break;
            }
        }
        if(i_RInd == -1 || i_CInd == -1){
            return false;
        }
        cl2p_Ptr[i_RInd][i_CInd] = 1;
    }

    public: ~AdList(){
        for(int i_Ct =0; i_Ct< i_Size; i_Ct++){
            delete [] cl2p_Ptr[i_Ct];
        }
        delete [] cl2p_Ptr;
    }
};

int main(){
    char c_Arr[] = {'A', 'B', 'C', 'D', 'E'};
    int i_Size  = sizeof(c_Arr)/sizeof(char);
    AdList o_List = AdList(c_Arr, i_Size);
    o_List.fn_InsVet('A', 'A');
    o_List.fn_InsVet('A', 'B');
    o_List.fn_InsVet('A', 'C');
    o_List.fn_InsVet('A', 'D');

    for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
        for(int i_Ct2= 0; i_Ct2 < i_Size; i_Ct2++){
            std::cout<< o_List.cl2p_Ptr[i_Ct][i_Ct2] << " ";
        }
        std::cout<< "\n";
    }

    return 0;
}
