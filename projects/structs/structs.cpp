#include <iostream>
#include <cstdlib>
using namespace std;

//queue stack set later

struct data {
    int value;
    struct data * next;
};

void print_linked_list(struct data *header){
    struct data *tmp = header;
    int rank =0;
    while(tmp != NULL)
    {
        cout<<"Record "<<rank<<" value = "<<tmp->value<<"\n";
        tmp = tmp->next;
        rank++;
    }
    
    cout<<"\n\n";
}

void search_linked_list(struct data *header, int index, struct data* &prior)
{
        struct data *tmp = header;
    int rank =0;
    while(tmp != NULL)
    {
        if(rank == index)
        {
            
            cout<<"The "<<rank<<"-th record value = "<<tmp->value<<"\n";
            break;
        }
        prior = tmp;
        tmp = tmp->next;
        rank++;
    }
    cout<<"\n\n";
}

int main(int args, char **argv) {
	//cout << "Start";
    int num_inserts = 3;
    int num_deletes = 1;
    int num_searches = 1;

    struct data *header = new struct data;
    header->value=360;
    header->next = NULL;
    //Linked list

    //insertion
    for(int i=0;i<num_inserts;i++){
        struct data *instance = new struct data;
        instance->value = rand()%360;
        instance->next = NULL;
        //record the old next of the header
        struct data *tmp = header->next;
        //change the header's next to this new instance
        header->next = instance;
        //point new instance to old next
        instance->next = tmp;
        cout<<"Value "<<instance->value<<" is inserted\n";
        print_linked_list(header);
    }    

    //deletion
    for(int i=0;i<num_deletes;i++)
    {

        int delete_index = rand()%(num_inserts+1);
        cout<<"I will delete the "<<delete_index<<"-th record. \n";
        if(delete_index ==0)
        {
            header = header->next;
        }
        else{
            struct data *prior;
            search_linked_list(header, delete_index, prior);
            //std::cout<<"I got prior->value ="<<prior->value<<"\n";
            prior->next = prior->next->next;
        
        }
        
       
        print_linked_list(header);
    }

    
    return 0;
}
