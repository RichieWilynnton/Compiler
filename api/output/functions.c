typedef struct {
    void* (*lambda) (Element[]);
    Element *env;
    int env_size;
} Closure;

typedef struct {
    void *data;
    DataType type;
} Element;

typedef enum {
    INT,
    FLOAT,
    BOOLEAN,
    STRING
} DataType;

#define DEFINE_MAKE_ELEMENT(datatype, type_enum)       \
    Element make_##datatype##_element(datatype value) {        \
        datatype* ptr = (datatype*) malloc(sizeof(datatype));   \
        *ptr = value; \
        Element ret = { \
            .data = ptr, \
            .type = type_enum \
        };              \
        return ret;                                            \
    }\


int addnum(Element env[]) {
    // compiler lists out all values in env and re-declares using index of env
    // return a + b
    return 0;
}

void freeClosure(Closure c) {
    for (int i=0; i<c.env_size; i++) {
        free(c.env[i].data);
    }
}

DEFINE_MAKE_ELEMENT(int, INT);

int main() {
    // env will always be same scope as closure, so dont worry about passing stack-allocated env to closure
    Element env[] = {make_int_element(1)};
    addnum(env);
    // runClosure(&addnum, )
}