#ifndef EMBEDDED_DATA_H
#define EMBEDDED_DATA_H

#include "../permissions/permissions.h"

#define Data_XXX_Information_Struct_Gen(name_in_struct, name_in_variables )	struct Data_ ##name_in_struct ##_Information {							     \
		void* data_all_data_ ##name_in_variables;			\
		int*  data_num_times_ ##name_in_variables;			\
		int*  data_indexes_of_data_ ##name_in_variables; 		\
	}

#define Data_XXX_Information_Struct_Typedef(name_in_struct, name_in_typedef) typedef struct Data_ ##name_in_struct ##_Information DATA_ ##name_in_typedef ##_INFORMATION

Data_XXX_Information_Struct_Gen(Add, added);
Data_XXX_Information_Struct_Gen(Remove, removed);
Data_XXX_Information_Struct_Gen(Insert, inserted);
Data_XXX_Information_Struct_Typedef(Add, ADD);
Data_XXX_Information_Struct_Typedef(Remove, REMOVE);
Data_XXX_Information_Struct_Typedef(Insert, INSERT);

struct Data_Alteration_Information {
	DATA_ADD_INFORMATION data_add_information;
	DATA_REMOVE_INFORMATION data_remove_information;
	DATA_INSERT_INFORMATION data_insert_information;
};

struct Embedded_Data_Information {
	int   data_unit_byte_size;
	int   data_bytes_num;
	int   data_bytes_max;
	DATA_ALTERATION_INFORMATION data_alteration_information;
}; 

typedef struct Embedded_Data_Information EMBEDDED_DATA_INFORMATION;

struct Embedded_Data_Entry {
	void* entry;
	time_t time_entry_created;
};

typedef struct Embedded_Data_Entry EMBEDDED_DATA_ENTRY;
typedef EMBEDDED_DATA_ENTRY* EMBEDDED_DATA_ENTRIES;

struct Embedded_Data {
	char* name;
	void* data;
	EMBEDDED_DATA_ENTRIES embedded_data_entries;
	PERMISSIONS  permissions;
	PERMISSIONS* permissions_previous;
	EMBEDDED_DATA_INFORMATION embedded_data_information;
};

typedef struct Embedded_Data EMBEDDED_DATA;

#endif /* EMBEDDED_DATA_H */
