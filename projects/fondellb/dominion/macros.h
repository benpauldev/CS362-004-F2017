//
//  macros.h
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//

#ifndef macros_h
#define macros_h

#define STR(x) #x
#define MY_ASSERT(x){if(!(x)){printf("TEST FAILED!   Line:%i   File:%s\n",__LINE__,__FILE__);}}
#define MY_ASSERT_TOO(x){if(!(x)){TESTS_FAILED++;break;}}



#endif /* macros_h */
