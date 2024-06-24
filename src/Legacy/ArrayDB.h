///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Header file for Cat array database.
///
/// @file    ArrayDB.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_ARRAYDB_H
#define EE205_ANIMAL_FARM_ARRAYDB_H

/// Allowed number of cats in array
#define MAX_CATS	(10)

extern int numCats;

extern struct Cat catArray[];

extern bool initDB();

extern bool AddCat(struct Cat catStructure, struct Cat catArray[MAX_CATS]);

extern bool validateCatDB(struct Cat catArray[MAX_CATS]);

#endif //EE205_ANIMAL_FARM_ARRAYDB_H


