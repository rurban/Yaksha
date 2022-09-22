// YK
#include "yk__lib.h"
// --forward declarations-- 
int32_t yy__to_lengths(yk__sds, int32_t);
int32_t yy__to_pow2(int32_t, int32_t);
bool yy__print_int(int32_t, int32_t);
int32_t yy__main();
// --structs-- 
// --functions-- 
int32_t yy__to_lengths(yk__sds yy__a, int32_t yy__ignored) 
{
    int32_t t__0 = yk__sdslen(yy__a);
    yk__sdsfree(yy__a);
    return t__0;
}
int32_t yy__to_pow2(int32_t yy__a, int32_t yy__ignored) 
{
    int32_t t__1 = (yy__a * yy__a);
    return t__1;
}
bool yy__print_int(int32_t yy__a, int32_t yy__ignored) 
{
    yk__printlnint(((intmax_t)yy__a));
    return true;
}
int32_t yy__main() 
{
    yk__sds t__2 = yk__sdsnew(">> map str test <<");
    yk__printlnstr((t__2));
    yk__sds t__3 = yk__sdsnew("Hello");
    yk__sds t__4 = yk__sdsnew("World");
    yk__sds t__5 = yk__sdsnew("How");
    yk__sds t__6 = yk__sdsnew("Are");
    yk__sds t__7 = yk__sdsnew("You");
    yk__sds* t__8 = NULL;
    yk__arrsetcap(t__8, 5);
    yk__arrput(t__8, yk__sdsdup(t__3));
    yk__arrput(t__8, yk__sdsdup(t__4));
    yk__arrput(t__8, yk__sdsdup(t__5));
    yk__arrput(t__8, yk__sdsdup(t__6));
    yk__arrput(t__8, yk__sdsdup(t__7));
    yk__sds* yy__ar = t__8;
    yk__sds t__9 = yk__sdsnew("map to_lengths ==> ");
    yk__printlnstr((t__9));
    yk__sds* t__12 = yy__ar;
    int32_t t__14 = 0;
    size_t t__11 = yk__arrlenu(t__12);
    int32_t* t__15 = NULL;
    for (size_t t__10 = 0; t__10 < t__11; t__10++) { 
        yk__sds t__13 = yk__sdsdup(t__12[t__10]);
        int32_t t__16 = yy__to_lengths(t__13, t__14);
        yk__arrput(t__15, t__16);
    }
    int32_t* t__19 = t__15;
    int32_t t__21 = 0;
    size_t t__18 = yk__arrlenu(t__19);
    bool t__22 = true;
    for (size_t t__17 = 0; t__17 < t__18; t__17++) { 
        int32_t t__20 = t__19[t__17];
        bool t__23 = yy__print_int(t__20, t__21);
        if (!t__23) {t__22 = false; break; }
    }
    t__22;
    yk__sds t__24 = yk__sdsnew(">> countif int test <<");
    yk__printlnstr((t__24));
    int32_t* t__25 = NULL;
    yk__arrsetcap(t__25, 10);
    yk__arrput(t__25, 1);
    yk__arrput(t__25, 2);
    yk__arrput(t__25, 3);
    yk__arrput(t__25, 4);
    yk__arrput(t__25, 5);
    yk__arrput(t__25, 6);
    yk__arrput(t__25, 7);
    yk__arrput(t__25, 8);
    yk__arrput(t__25, 9);
    yk__arrput(t__25, 10);
    int32_t* yy__ai = t__25;
    yk__sds t__26 = yk__sdsnew("map to_pow2 ==> ");
    yk__printlnstr((t__26));
    int32_t* t__29 = yy__ai;
    int32_t t__31 = 0;
    size_t t__28 = yk__arrlenu(t__29);
    int32_t* t__32 = NULL;
    for (size_t t__27 = 0; t__27 < t__28; t__27++) { 
        int32_t t__30 = t__29[t__27];
        int32_t t__33 = yy__to_pow2(t__30, t__31);
        yk__arrput(t__32, t__33);
    }
    int32_t* t__36 = t__32;
    int32_t t__38 = 0;
    size_t t__35 = yk__arrlenu(t__36);
    bool t__39 = true;
    for (size_t t__34 = 0; t__34 < t__35; t__34++) { 
        int32_t t__37 = t__36[t__34];
        bool t__40 = yy__print_int(t__37, t__38);
        if (!t__40) {t__39 = false; break; }
    }
    t__39;
    yk__sds t__41 = yk__sdsnew("completed.");
    yk__printlnstr((t__41));
    yk__sdsfree(t__41);
    yk__sdsfree(t__26);
    yk__sdsfree(t__24);
    yk__sdsfree(t__9);
    yk__sdsfree(t__7);
    yk__sdsfree(t__6);
    yk__sdsfree(t__5);
    yk__sdsfree(t__4);
    yk__sdsfree(t__3);
    yk__sdsfree(t__2);
    return 0;
}
#if defined(YK__MINIMAL_MAIN)
int main(void) { return yy__main(); }
#endif