//
// Created by hubert on 05.03.18.
//

/*
 * 
int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector<int> max_number_vector;
    std::vector < int >::const_iterator begin_vector;
    std::vector < int >::const_iterator min_index;
    int min_numer;

    std::vector<int> max_number_vector_2;
    std::vector < int >::const_iterator begin_vector_2;
    std::vector < int >::const_iterator maks_index_2;
    int maks_numer_2;

    std::vector<int> max_number_vector_3;
    std::vector < int >::const_iterator begin_vector_3;
    std::vector < int >::const_iterator maks_index_3;
    int maks_numer_3;

    for(int v : numbers) {

        if(k%2 != 0){
            if(max_number_vector_3.size() < k-1){
                max_number_vector_3.push_back(v);
            }
        }

        if(max_number_vector.size() < k){
            max_number_vector.push_back(v);
        }
        if(max_number_vector_2.size() < k){
            max_number_vector_2.push_back(v);
        }

        else{
            begin_vector = max_number_vector.begin();
            min_index = max_number_vector.begin();
            min_numer=100000;
            for(int x : max_number_vector) {
                if (min_numer > x) {
                    min_numer = x;
                    min_index = begin_vector;
                }
                begin_vector++;
            }
            if(v > min_numer){
                max_number_vector.erase(min_index);
                max_number_vector.insert(min_index, v);
            }

            if(k%2 == 0) {
                begin_vector_2 = max_number_vector_2.begin();
                maks_index_2 = max_number_vector_2.begin();
                maks_numer_2 = 0;
                for (int x : max_number_vector_2) {
                    if (maks_numer_2 < x) {
                        maks_numer_2 = x;
                        maks_index_2 = begin_vector_2;
                    }
                    begin_vector_2++;
                }
                if (v < maks_numer_2) {
                    max_number_vector_2.erase(maks_index_2);
                    max_number_vector_2.insert(maks_index_2, v);
                }
            }
            else{
                begin_vector_3 = max_number_vector_3.begin();
                maks_index_3 = max_number_vector_3.begin();
                maks_numer_3 = 0;
                for (int x : max_number_vector_3) {
                    if (maks_numer_3 < x) {
                        maks_numer_3 = x;
                        maks_index_3 = begin_vector_3;
                    }
                    begin_vector_3++;
                }
                if (v < maks_numer_3) {
                    max_number_vector_3.erase(maks_index_3);
                    max_number_vector_3.insert(maks_index_3, v);
                }
            }




        }
    }
    int max_plus=0;



    int iloczyn = 1;
    for(int i : max_number_vector){
        if(i>max_plus){
            max_plus = i;
        }
        iloczyn *=i;
    }

    int iloczyn_2 = 1;
    for(int a : max_number_vector_2){
        iloczyn_2 *=a;
    }

    int iloczyn_3 = 1;
    for(int b : max_number_vector_3){
        iloczyn_3 *=b;
    }
    iloczyn_3 *= max_plus;
    max_number_vector.clear();

    std::cout<< "@@  " << iloczyn << " -@- " << iloczyn_2 << " -@- " << iloczyn_3<<"\n";

    if(iloczyn>iloczyn_2 && iloczyn>iloczyn_3){
        return iloczyn;
    }
    else
    {
        if(iloczyn_2>iloczyn_3) return iloczyn_2;

    }
    return iloczyn_3;





}

 * 
 */