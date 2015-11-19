#include<stdio.h>
#include<stdlib.h>

#define     HASH_TABLE_INIT_SIZE    100
#define     SUCESS                  1
#define     FAILED                  0

typedef struct _Bucket
{
    char *key;
    void *value;
    struct _Bucket *next;
}Bucket;

typedef struct _HashTable
{
    int size;
    int elem_num;
    Bucket** buckets;
}HashTable;

int hash_init(HashTable *ht);                               // 初始化哈希表
int hash_lookup(HashTable *ht, char *key, void **result);   // 根据key查找内容
int hash_insert(HashTable *ht, char *key, void *value);     // 将内容插入到哈希表中
int hash_remove(HashTable *ht, char *key);                  // 删除key所指向的内容
int hash_destroy(HashTable *ht);

static int hash_str(char *key)
{
    int hash = 0;

    char *cur = key;

    while(*cur != '\0') {
        hash += *cur;
        ++cur;
    }
    return hash;
}
#define HASH_INDEX(ht, key) (hash_str(key)) % (ht)->size)


int hash_init(HashTable *ht){
    ht->size        = HASH_TABLE_INIT_SIZE;
    ht->elem_num    = 0;
    ht->buckets     = (Bucket **)calloc(ht->size, sizeof(Bucket *));

    if( ht->buckets == NULL ) { return FAILED; }

    return SUCESS;
}
int hash_insert(HashTable *ht, char *key, void *value)
{
    //resize_hash_table_if_needed(ht);

    int index = HASH_INDEX(ht, key);

    Bucket *org_bucket = ht->buckets[index];
    Bucket *tmp_bucket = org_bucket;

    // check if the key exits already
    while(tmp_bucket)
    {
        if(strcmp(key, tmp_bucket->key) == 0)
        {
            tmp_bucket->value = value;

            return SUCCESS;
        }

        tmp_bucket = tmp_bucket->next;
    }

    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));

    bucket->key   = key;
    bucket->value = value;
    bucket->next  = NULL;

    ht->elem_num += 1;

    if(org_bucket != NULL)
    {
        bucket->next = org_bucket;
    }

    ht->buckets[index]= bucket;

    return  SUCCESS;
}
int main(){
    /*
       char *str = "this is a test string;";
       int key  = hash_str( str );
       printf("%d",key);
       */
    return 0;
}
