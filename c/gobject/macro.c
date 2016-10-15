G_DEFINE_TYPE(TN, t_n, T_P)
	Class initialization function 
	Instance initialization function (GTypeInfo)
	t_n_parent_class
	*_get_type()

G_DEFINE_TYPE_WITH_PRIVATE
	adds private instance type 

G_DECLARE_FINAL_TYPE 
	GType t_n_get_type()
	sets typedef of _TN as TN and _TNClass as TNClass. The struct TN is not defined,
	and must be defined before G_DEFINE_TYPE in the .c file
	TNClass is defined with the parent class 
	T_N() cast and T_IS_N() type checking is defined (as static inline function)
	TNClassType is defined as a struct 





