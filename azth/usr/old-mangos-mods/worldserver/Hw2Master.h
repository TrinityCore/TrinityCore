/* 
 * File:   Hw2Master.h
 * Author: giuseppe
 *
 * Created on 31 agosto 2013, 9.32
 */

#ifndef HW2MASTER_H
#define	HW2MASTER_H

#include "thrift.h"

class Hw2Master {
public:
    Hw2Master();
    Hw2Master(const Hw2Master& orig);
    virtual ~Hw2Master();
    static void run();
private:

};

#endif	/* HW2MASTER_H */

