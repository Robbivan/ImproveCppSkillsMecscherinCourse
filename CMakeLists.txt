cmake_minimum_required(VERSION 3.23)
project(Mecha)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mecha main.cpp references.h consts.h OOP.h StringClass.h operators.h static_fields.h Singleton.h explicit-methods.h callback_functors_comparators.h OOP2.h multiple_inheritance.h virtual_inheritance.h polymorphism.h abstract_classes_and_pure_virtual_functions.h virtual_destructor.h RTTI_dynamic_cast.h Templates/templates_intro.h Templates/template_overloading.cpp Templates/template_specialization.cpp Templates/non_type_templates_parametrs.cpp Templates/dependent_names_problem.cpp Templates/type_traits_and_metafunctions.cpp testcl.cpp Templates/variadic_templates.cpp Templates/template_deduction_rules.cpp Exceptions/exceptions.cpp)
