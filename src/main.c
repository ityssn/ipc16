#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "string.h"

typedef struct Person Person;
typedef struct Person
{
   int age;
   char name[20];
   void (*set_age)( Person *pthis, const int age);
   void (*set_name)( Person *pthis, const char name[20]);
   void (*get_age)( Person *pthis, const int *age);
   void (*get_name)(Person *pthis, const char name[20]);
   void (*print_msg)( Person *pthis);
}
Person;


void person_set_age(Person *pthis, const int age){
    pthis -> age = age;
}

void person_set_name(Person *pthis, const char name[20]){
   strcpy(pthis->name, name);
}

void person_get_age(Person *pthis, int *age){
   *age =  pthis -> age;
}

void person_get_name(Person *pthis, char name[20]){
   strcpy(name, pthis->name);
}


void person_print_msg(Person *pthis){
 
   printf("%d %s\n",pthis -> age,pthis -> name);

}


Person* CreatPersonClass(void){
     Person* person =(Person*)malloc(sizeof(Person));
     if(person==NULL){
          printf("person null");
          return NULL;
     }
    person -> set_age   = person_set_age;
    person -> set_name  = person_set_name;
    person -> get_age   = person_get_age;
    person -> get_name  = person_get_name;
    person -> print_msg = person_print_msg;
     return person;
}



Person* CreatPersonClassWithArgs(const int age,const char name[20]){
       Person* person = CreatPersonClass();
      if(person==NULL){
          printf("person null");
          return NULL;}
      person -> age =age;
      strcpy(person -> name, name);
      return person;

}



int main(void){
      char tmp_name[20] = "Jack";
      int tmp_age = 0;
    Person* jack = CreatPersonClassWithArgs(18,tmp_name); 
    
    jack->set_age(jack , 21);
    jack->set_name(jack ,"Junne");

    jack->print_msg(jack);

    jack->get_age(jack , &tmp_age);
    jack->get_name(jack ,tmp_name);

    printf("%d   %s\n",tmp_age,tmp_name);
    return 0;


     return 0;

}