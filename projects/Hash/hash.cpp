#include <iostream>

#define INIT (1<<31)
#define YES 1
#define NO 0


int hash_function(int element, int size){
    return (element%size);
}


int insert(int *hash_table, int size, int element){
    int index = hash_function(element);
    if(hash_table[index]==element) return -1;

}

int search(int *hash_table, int size, int element, int &index){
    
    int is_found = NO;
    index = hash_function(element);
    int trial = 1;

    while(hash_table[index] != element){
        
        index ++;
        index = index%size;

        if(hash_table[index] == element){
            is_found = YES;
            break;
        }

        trial ++;

        if(trial == size) break;

    }

    return is_found;
}


int delete_element(int *hash_table, int size, int element){



}


int construct_hash_table(int *&hash_table, int size){

    hash_table = new int[size];

    for (int i = 0; i < size; i ++)
        hash_table[i] = INIT;

    return 0;
}



int main (int args, char **argv)
{
    std::cout<<"This is a hash table with linear probing collision handling mechanism\n";

    std::cout<<"/path/to/exe size_of_hash_table num_of_elements_to_insert\n";

    assert(args>=3);

    int size = atoi(argv[1]);

    int num = atoi(argv[2]);

    int *hash_table; 
    assert(0==construct_hash_table (hash_table, size));

    for(int i = 0; i < num; i ++){
        int element = rand()%12;
        insert(hash_table, element, size);
    }
    
    return 0;
}