//
// Created by hubert on 04.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H



template <class T, class B>
class SequentialIdGenerator {
public:
    SequentialIdGenerator(){
        b = 0;
    }

    SequentialIdGenerator(B base){
        b = base;
    }

    T NextValue(){
        T temp = T(b);
        ++b;
        return temp;
    }

private:
    B b;
};



#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
