#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/BitWriter.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct binary_operator{
  int OP_CODE;

};
LLVMModuleRef mod = LLVMModuleCreateWithName("my_module");
/*LLVMTypeRef param_types[] = {  };
LLVMTypeRef ret_type = LLVMFunctionType(LLVMInt32Type(), param_types, 0, 0);
LLVMValueRef sum = LLVMAddFunction(mod, "main", ret_type);
LLVMBasicBlockRef entry = LLVMAppendBasicBlock(sum, "entry");*/
LLVMBuilderRef builder = LLVMCreateBuilder();

LLVMTypeRef PrintfArgsTyList[] = { LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef PrintfTy = LLVMFunctionType(
        LLVMInt32Type(),
        PrintfArgsTyList,
        0,
        true // IsVarArg
    );

struct identifier_linked_list{
  char identifier[20];
  LLVMValueRef valueref;
  int integervalue;
  int floatingvalue;
  int stringvalue;
  struct identifier_linked_list *next_identifier;
};
struct integer_float_values{
  char identifier[90];
  int identifiervalue;
  LLVMValueRef valueref;
  int integervalue;
  int floatingvalue;
};

struct function_args_list{
  char identifier[90];
  int integervalue;
  struct function_args_list *next_arg;
};

struct function_linked_list{
  char identifier[20];
  LLVMValueRef valueref;
  int integervalue;
  int floatingvalue;
  int stringvalue;
  struct function_args_list function_args_list1;
  struct function_linked_list *next_identifier;
};

struct identifier_linked_list identifiers_list;
struct function_linked_list function_linked_list1;

void start(){
LLVMValueRef PrintfFunction = LLVMAddFunction(mod, "printf", PrintfTy);



}

void expression(struct integer_float_values tmp){
  LLVMBuildRet(builder, tmp.valueref);
}

struct integer_float_values integer_parse_tree(int a){
  struct integer_float_values i;
      i.integervalue = 1;
      i.floatingvalue = 0;
      i.valueref = LLVMConstInt(LLVMInt32Type(),a,0);
      return i;
}

struct integer_float_values float_parse_tree(float a){
  struct integer_float_values i;
      i.floatingvalue = 1;
      i.integervalue = 0;
      i.valueref = LLVMConstReal(LLVMFloatType(),a); 
  return i;
}

void variable_declare(int integervalue,char identifier[]){
  struct identifier_linked_list *identifiers_list1 = &identifiers_list;
  while(identifiers_list1->next_identifier!=NULL){
    if(strcmp(identifiers_list1->identifier,identifier)==0){
      printf("Identifier declaration found\n");
      return;
    }
    identifiers_list1 = identifiers_list1->next_identifier;
  }
  identifiers_list1->next_identifier = (struct identifier_linked_list*) malloc(sizeof(struct identifier_linked_list));
  strcpy(identifiers_list1->identifier,identifier);

  if(integervalue == 0){
    identifiers_list1->integervalue=1;
    identifiers_list1->floatingvalue=0;
    identifiers_list1->valueref=LLVMAddGlobal(mod,LLVMInt32Type(),identifier);
    LLVMSetInitializer(identifiers_list1->valueref,LLVMConstInt(LLVMInt32Type(),0,0));
  }
  else if(integervalue == 1){
    identifiers_list1->floatingvalue=1;
    identifiers_list1->integervalue=0;
    identifiers_list1->valueref=LLVMAddGlobal(mod,LLVMFloatType(),identifier);
    LLVMSetInitializer(identifiers_list1->valueref,LLVMConstReal(LLVMFloatType(),0));
  }
  else if(integervalue == 2){
    identifiers_list1->stringvalue=1;
    identifiers_list1->valueref=LLVMAddGlobal(mod,LLVMPointerType(LLVMInt8Type(),90),identifier);
    
  }
}



struct integer_float_values integer_float_values_identifier(char identifier[]){
  struct identifier_linked_list *identifiers_list1 = &identifiers_list;
  while(identifiers_list1->next_identifier!=NULL){
    if(strcmp(identifiers_list1->identifier,identifier)==0 && identifiers_list1->integervalue == 1){
      struct integer_float_values a;
      a.integervalue = 1;
      a.floatingvalue = 0;
      a.identifiervalue=1;
      strcpy(a.identifier,identifier);
      a.valueref = LLVMGetInitializer(identifiers_list1->valueref);
      return a;
    }
    else if(strcmp(identifiers_list1->identifier,identifier)==0 && identifiers_list1->floatingvalue == 1){
      struct integer_float_values a;
      a.floatingvalue = 1;
      a.integervalue = 0;
      a.identifiervalue = 1;
      strcpy(a.identifier,identifier);
      a.valueref = LLVMGetInitializer(identifiers_list1->valueref);
      return a;
    }
    identifiers_list1 = identifiers_list1->next_identifier;
  }

  printf("Identifier Not declared \n");
  
}

void identifier_value_expression(struct integer_float_values identifier,struct integer_float_values value){
   if(value.integervalue == 1){
      struct integer_float_values a;
      a.integervalue = 1;
      if(identifier.integervalue == 1){
        LLVMSetInitializer(LLVMGetNamedGlobal(mod,identifier.identifier),LLVMConstInt(LLVMInt32Type(),LLVMConstIntGetSExtValue(value.valueref),0));  
      }
      else if(identifier.floatingvalue == 1){
        LLVMSetInitializer(LLVMGetNamedGlobal(mod,identifier.identifier),LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(value.valueref)));
      
      }
      return;
    }
    else if(value.floatingvalue == 1){
      struct integer_float_values a;
      a.floatingvalue = 1;
      int arr[] = {};
      if(identifier.integervalue == 1){
        LLVMSetInitializer(LLVMGetNamedGlobal(mod,identifier.identifier),LLVMConstInt(LLVMInt32Type(),(int)LLVMConstRealGetDouble(value.valueref,arr),0));
        
      }
      else if(identifier.floatingvalue == 1){
        LLVMSetInitializer(LLVMGetNamedGlobal(mod,identifier.identifier),LLVMConstReal(LLVMFloatType(),(float)LLVMConstRealGetDouble(value.valueref,arr)));
      
      }
      return;
    }
  printf("Identifier not found\n");
}

struct integer_float_values expression_parse_tree_addition(struct integer_float_values LHS, struct integer_float_values RHS){
  struct integer_float_values a;
  if(LHS.floatingvalue == 1 || RHS.floatingvalue == 1){
    if(LHS.floatingvalue == 1 && RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      a.integervalue = 0;
      a.valueref = LLVMBuildFAdd(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(LHS.floatingvalue == 1){
      a.floatingvalue = 1;
      a.integervalue = 0;
      RHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(RHS.valueref));
      a.valueref = LLVMBuildFAdd(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      a.integervalue = 0;
      LHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(LHS.valueref));
      a.valueref = LLVMBuildFAdd(builder,LHS.valueref,RHS.valueref,"add"); 
    }
    return a;
  }
  else{
    a.integervalue=1;
    a.floatingvalue = 0;
    a.valueref = LLVMBuildAdd(builder,LHS.valueref,RHS.valueref,"add");
    return a;
  }

}

struct integer_float_values expression_parse_tree_subtraction(struct integer_float_values LHS, struct integer_float_values RHS){
   struct integer_float_values a;
  if(LHS.floatingvalue == 1 || RHS.floatingvalue == 1){
    if(LHS.floatingvalue == 1 && RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      a.valueref = LLVMBuildFSub(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(LHS.floatingvalue == 1){
      a.floatingvalue = 1;
      RHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(RHS.valueref));
      a.valueref = LLVMBuildFSub(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      LHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(LHS.valueref));
      a.valueref = LLVMBuildFSub(builder,LHS.valueref,RHS.valueref,"add"); 
    }
    return a;
  }
  else{
    a.integervalue=1;
    a.valueref = LLVMBuildSub(builder,LHS.valueref,RHS.valueref,"add");
    return a;
  }
}
struct integer_float_values expression_parse_tree_multiplication(struct integer_float_values LHS, struct integer_float_values RHS){
   struct integer_float_values a;
  if(LHS.floatingvalue == 1 || RHS.floatingvalue == 1){
    if(LHS.floatingvalue == 1 && RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      a.valueref = LLVMBuildFMul(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(LHS.floatingvalue == 1){
      a.floatingvalue = 1;
      RHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(RHS.valueref));
      a.valueref = LLVMBuildFMul(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      LHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(LHS.valueref));
      a.valueref = LLVMBuildFMul(builder,LHS.valueref,RHS.valueref,"add"); 
    }
    return a;
  }
  else{
    a.integervalue=1;
    a.valueref = LLVMBuildMul(builder,LHS.valueref,RHS.valueref,"add");
    return a;
  }
}
struct integer_float_values expression_parse_tree_division(struct integer_float_values LHS, struct integer_float_values RHS){
   struct integer_float_values a;
  if(LHS.floatingvalue == 1 || RHS.floatingvalue == 1){
    if(LHS.floatingvalue == 1 && RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      a.valueref = LLVMBuildFDiv(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(LHS.floatingvalue == 1){
      a.floatingvalue = 1;
      RHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(RHS.valueref));
      a.valueref = LLVMBuildFDiv(builder,LHS.valueref,RHS.valueref,"add");
    }
    else if(RHS.floatingvalue == 1){
      a.floatingvalue = 1;
      LHS.valueref = LLVMConstReal(LLVMFloatType(),(float)LLVMConstIntGetSExtValue(LHS.valueref));
      a.valueref = LLVMBuildFDiv(builder,LHS.valueref,RHS.valueref,"add"); 
    }
    return a;
  }
  else{
    a.integervalue=1;
    a.valueref = LLVMBuildUDiv(builder,LHS.valueref,RHS.valueref,"add");
    return a;
  }
}

struct function_args_list addtofunctionargs1(int integervalue,struct integer_float_values integer_float_values1){
  if(integervalue == 9){
  struct function_args_list a;
  a.integervalue=integervalue;
  return a;  
  }
  struct function_args_list a;
  a.integervalue=integervalue;
  strcpy(a.identifier,integer_float_values1.identifier);
  return a;
}

struct function_args_list addtofunctionargs(int integervalue,struct integer_float_values integer_float_values1,struct function_args_list temp){
struct function_args_list a;
  a.integervalue=integervalue;
  strcpy(a.identifier,integer_float_values1.identifier);
  a.next_arg = &temp;
  return a;
}

void addtofunctions(int integervalue,struct function_linked_list temp,struct function_args_list function_args_list1){
  struct function_linked_list* a = &function_linked_list1;
  if(a == NULL){
    a=&temp;
    temp.integervalue = integervalue;
    temp.function_args_list1 = function_args_list1;
    return;
  }
  else{
  while(a->next_identifier!=NULL){
    a=a->next_identifier;
  }
  }
  temp.integervalue = integervalue;
  temp.function_args_list1 = function_args_list1;
  a->next_identifier = &temp;
  return;
}

struct function_linked_list addtofunctions1(char identifier[]){
  struct function_linked_list a;
  strcpy(a.identifier,identifier);
  return a;
}

void addfunctions(int integervalue,struct function_linked_list function_linked_list1,struct function_args_list function_args_list1){
  LLVMTypeRef param_types[90];
  int i=0;
  struct function_args_list *a = &function_args_list1;
  int temp=0;
  if(a->integervalue==9){
    temp=0;
  }
  else{
  while(a!=NULL){
    if(a->integervalue==0){
      param_types[i]=LLVMInt32Type();
      i++;
    }
    else if(a->integervalue==1){
      param_types[i]=LLVMFloatType();
      i++;
    }
    a=a->next_arg;
    temp++;
  }
  }
  LLVMTypeRef ret_type;
  if(integervalue==0){
  ret_type = LLVMFunctionType(LLVMInt32Type(), param_types, temp, 0);
  }
  else if(integervalue==1){
  ret_type = LLVMFunctionType(LLVMFloatType(), param_types, temp, 0);  
  }
  LLVMValueRef sum = LLVMAddFunction(mod, function_linked_list1.identifier, ret_type);
  LLVMBasicBlockRef entry = LLVMAppendBasicBlock(sum, "entry");
  LLVMPositionBuilderAtEnd(builder, entry);

}
