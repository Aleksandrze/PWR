
#include "pch.h"
#include <iostream>

/*
Zaalokuje jednowymiarową tablicę zmiennych typu int. Wypełnienie i wypis na ekran.
*/
void v_alloc_table_add_5(int iSize)
{
	int *pi_tab;
	pi_tab = new int[iSize];

	if (iSize > 0)
	{
		for (int ii = 0; ii < iSize; ii++)
		{
			pi_tab[ii] = ii + 5;
			std::cout << pi_tab[ii] << " ";
		} 
		std::cout << std::endl;
	}  
	else
	{
		std::cout << "Size < 0" << std::endl;
	} 
	delete pi_tab;
} 



/*
Alokuje dwuwymiarową tablicę dla typu int,  dla  parameteru  podanego  w piTable.
*/
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {

	if (iSizeX > 0 && iSizeY > 0)
	{
		int **pi_Tab = new int*[iSizeX];
		for (int ii = 0; ii < iSizeX; ii++) 
		{
			pi_Tab[ii] = new int[iSizeY];
		}

		for (int ii = 0; ii < iSizeX; ii++)
		{
			for (int jj = 0; jj < iSizeY; jj++)
			{
				pi_Tab[ii][jj] = ii * jj + 5;
			}
		}
		*piTable = pi_Tab;


		for (int ii = 0; ii < iSizeX; ii++)
		{
			for (int jj = 0; jj < iSizeY; jj++)
			{
				std::cout << pi_Tab[ii][jj] << " ";
			}
			std::cout << std::endl;
		}
			std::cout << std::endl;
		return true;
	}
	return false;
}
	
/*
Dealokuje dwuwymiarową tablicę typu int
*/
	bool b_deaalloc_table_2_dim(int **piTable, int iSizeX, int iSizeY) 
	{
		if (iSizeX > 0 && iSizeY > 0) 
		{
			for (int ii = 0; ii < iSizeX; ii++)
			{
				delete piTable[ii];
			}
			delete piTable;
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}
	

	void v_mod_alloc_table_add_5(int iSizeX, int iSizeY)
	{
		char** pi_tab;
		if (iSizeX > 0 && iSizeY > 0)
		{
			pi_tab = new char*[iSizeX];
			for (int ii = 0; ii < iSizeX; ii++)
			{
				pi_tab[ii] = new char[iSizeY];
			}

			for (int ii = 0; ii < iSizeX; ii++)
			{
				for (int jj = 0; jj < iSizeY; jj++)
				{
					pi_tab[ii][jj] = 'a';
				}
			}
			for (int ii = 0; ii < iSizeX; ii++)
			{
				for (int ij = 0; ij < iSizeY; ij++) {
					std::cout << pi_tab[ii][ij] << " ";
				}
				std::cout << std::endl;
			}
			for (int ii = 0; ii < iSizeX; ii++)
			{
				delete pi_tab[ii];
			}
			delete pi_tab;
		}
		else
		{
			std::cout << "Size < 0" << std::endl;
		}
	}

	int main()
	{
		v_alloc_table_add_5(5);
		std::cout << "--------------------------" << std::endl;

		int **pi_Table;
		std::cout << b_alloc_table_2_dim(&pi_Table, 4, 6) << std::endl;
		std::cout << "--------------------------" << std::endl;
		std::cout << b_deaalloc_table_2_dim(pi_Table, 4, 6) << std::endl;
		
		v_mod_alloc_table_add_5(5,4);




	}
