#ifndef PACKAGE_h
#define PACKAGE_h

#ifdef _MSC_VER
  #define DLL_EXPORT_SYM __declspec(dllexport)
  #define DLL_EXPORT_TEMPLATE
  #define DLL_IMPORT_SYM __declspec(dllimport)
#elif __GNUC__ >= 4 || defined(__clang__)
  #define DLL_EXPORT_SYM __attribute__ ((visibility("default")))
  #define DLL_EXPORT_TEMPLATE __attribute__ ((visibility("default")))
  #define DLL_IMPORT_SYM __attribute__ ((visibility("default")))
#else
  #define DLL_EXPORT_SYM
  #define DLL_EXPORT_TEMPLATE
  #define DLL_IMPORT_SYM
#endif

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C extern
#endif

#define IMPORT                          DLL_IMPORT_SYM
#define IMPORT_FCN                      DLL_IMPORT_SYM
#define IMPORT_VAR           extern     DLL_IMPORT_SYM
#define IMPORT_CLASS                    DLL_IMPORT_SYM
#define IMPORT_FRIEND                   DLL_IMPORT_SYM
#ifdef __cplusplus
  #define IMPORT_EXTERN_C    extern "C" DLL_IMPORT_SYM
#else
  #define IMPORT_EXTERN_C    extern     DLL_IMPORT_SYM
#endif
#define EXPORT_TEMPLATE                 DLL_EXPORT_TEMPLATE

#endif /* PACKAGE_h */