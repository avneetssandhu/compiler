
#define Data_XXX_Information_Struct_Gen(name_in_struct, name_in_variables )	struct Data_ ##name_in_struct ##_Information {							     \
		void* data_all_data_ ##name_in_variables ##ed;			\
		int*  data_num_times_ ##name_in_variables ##ed;			\
		int*  data_indexes_of_data_ ##name_in_variables ##ed; 		\
	}

Data_XXX_Information_Struct_Gen(Add, add);
