#define __STORMLIB_SELF__

#include "wmo.h"
#include "Stormlib.h"
#include "mpq.h"

using namespace std;


WMORoot::WMORoot(std::string &filename) : filename(filename)
{
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

bool WMORoot::open()
{

    MPQFile f(filename.c_str());
    if(f.isEof ())
    {
        printf("No such file.\n");
        return false;
    }

    size_t size;
    char fourcc[5];
    bbcorn1[3] = 0;
    bbcorn2[3]= 0;

    while (!f.isEof  ())
    {
        f.read(fourcc,4);
        f.read(&size, 4);

        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = f.getPos() + size;

        if (!strcmp(fourcc,"MOHD"))//header
        {

            f.read(&nTextures, 4);
            f.read(&nGroups, 4);
            f.read(&nP, 4);
            f.read(&nLights, 4);
            f.read(&nModels, 4);
            f.read(&nDoodads, 4);
            f.read(&nDoodadSets, 4);
            f.read(&col, 4);
            f.read(&RootID, 4);
            f.read(bbcorn1,12);
            f.read(bbcorn2,12);
            break;
        }
        /*
        else if (!strcmp(fourcc,"MOTX"))
        {

        }
        else if (!strcmp(fourcc,"MOMT"))
        {

        }
        else if (!strcmp(fourcc,"MOGN"))
        {

        }
        else if (!strcmp(fourcc,"MOGI"))
        {

        }
        else if (!strcmp(fourcc,"MOLT"))
        {

        }
        else if (!strcmp(fourcc,"MODN"))
        {

        }
        else if (!strcmp(fourcc,"MODS"))
        {

        }
        else if (!strcmp(fourcc,"MODD"))
        {

        }
        else if (!strcmp(fourcc,"MOSB"))
        {

        }
        else if (!strcmp(fourcc,"MOPV"))
        {

        }
        else if (!strcmp(fourcc,"MOPT"))
        {

        }
        else if (!strcmp(fourcc,"MOPR"))
        {

        }
        else if (!strcmp(fourcc,"MFOG"))
        {

        }
        */
        f.seek((int)nextpos);
    }
    f.close ();
    return true;
}
//---------------------------------------------------------------------------

bool WMORoot::ConvertToVMAPRootWmo(FILE *pOutfile)
{
    //printf("Convert RootWmo...\n");

    fwrite("VMAP002",1,8,pOutfile);
    unsigned int nVectors = 0;
    fwrite(&nVectors,sizeof(nVectors),1,pOutfile); // will be filled later
    fwrite(&nGroups,4,1,pOutfile);
    return true;
}

//----------------------------------------------------------------------------
WMORoot::~WMORoot()
{
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

WMOGroup::WMOGroup(std::string &filename) : filename(filename)
{
}
//---------------------------------------------------------------------------
bool WMOGroup::open()
{
    MPQFile f(filename.c_str());
    if(f.isEof ())
    {
        printf("No such file.\n");
        return false;
    }
    size_t size;
    char fourcc[5];
    bbcorn1[3] = 0;
    bbcorn2[3] = 0;
    while (!f.isEof  ())
    {
        f.read(fourcc,4);
        f.read(&size, 4);
        flipcc(fourcc);
        if (!strcmp(fourcc,"MOGP"))//Fix sizeoff = Data size.
        {
            size = 68;
        }
        fourcc[4] = 0;
        size_t nextpos = f.getPos() + size;
        LiquEx_size = 0;
        liquflags = 0;

        if (!strcmp(fourcc,"MOGP"))//header
        {
            f.seekRelative(-4);
            f.read(&offsize, 4);
            f.read(&flag, 4);
            f.read(&flag1, 4);
            f.read(&Xid, 4);
            f.read(bbcorn1, 12);
            f.read(bbcorn2, 12);
            f.read(&Xid2, 4);
            f.read(&Xid3, 4);
            f.read(&zero1, 4);
            f.read(&Xflag, 4);
            f.read(&nTexture,4);
            f.read(&GroupID,4);
        }
        else if (!strcmp(fourcc,"MOPY"))
        {
            MOPY = new char[size];
            mopy_size = size;
            nTriangles = (int)size / 2;
            f.read(MOPY, size);
        }
        else if (!strcmp(fourcc,"MOVI"))
        {
            MOVI = new uint16[size/2];
            f.read(MOVI, size);

        }
        else if (!strcmp(fourcc,"MOVT"))
        {
            MOVT = new float[size/4];
            f.read(MOVT, size);
            nVertices = (int)size / 12;
        }
        else if (!strcmp(fourcc,"MONR"))
        {
        }
        else if (!strcmp(fourcc,"MOTV"))
        {
        }
        else if (!strcmp(fourcc,"MOBA"))
        {
            MOBA = new uint16[size/2];
            moba_size = size/2;
            f.read(MOBA, size);
        }
        else if (!strcmp(fourcc,"MLIQ"))
        {
            liquflags |= 1;
            WMOLiquidHeader hlq;
            f.read(&hlq, 0x1E);
            float ydir = -1.0f;
            hlq_xverts = hlq.xverts;
            hlq_yverts = hlq.yverts;
            int noVer = hlq.xverts * hlq.yverts;
            float tilesize  = CHUNKSIZE / 8.0f;
            LiquEx_size = sizeof(float) * 3 * noVer;
            LiquEx = new float[sizeof(float) * 3 * noVer];
            int p = 0;

            for (int j=0; j<hlq.yverts; j++)
            {
                for (int i=0; i<hlq.xverts; i++)
                {
                    LiquEx[p++] = hlq.pos_x + tilesize * i;
                    LiquEx[p++] = hlq.pos_z;
                    LiquEx[p++] = ydir * (hlq.pos_y + tilesize * j);
                }
            }

        }
        f.seek((int)nextpos);
    }
    f.close ();
    return true;
}
//----------------------------------------------------------------------------
int WMOGroup::ConvertToVMAPGroupWmo(FILE *output, bool pPreciseVectorData)
{
	if(pPreciseVectorData) {
		fwrite(&liquflags,sizeof(uint32),1,output); 
		char GRP[] = "GRP ";
		fwrite(GRP,1,4,output);

		int k = 0;
		int moba_batch = moba_size/12;
		MobaEx = new int[moba_batch*4];
		for(int i=8; i<moba_size; i+=12)
		{
			MobaEx[k++] = MOBA[i];
		}
		delete [] MOBA;
		int moba_size_grp = moba_batch*4+4;
		fwrite(&moba_size_grp,4,1,output); 
		fwrite(&moba_batch,4,1,output);
		fwrite(MobaEx,4,k,output);
		delete [] MobaEx;

		uint32 nIdexes = nTriangles * 3;

		if(fwrite("INDX",4, 1, output) != 1) { printf("Error while writing file nbraches ID"); exit(0); }
		int wsize = sizeof(uint32) + sizeof(unsigned short) * nIdexes;
		if(fwrite(&wsize, sizeof(int), 1, output) != 1) { printf("Error while writing file wsize"); }
		if(fwrite(&nIdexes, sizeof(uint32), 1, output) != 1) { printf("Error while writing file nIndexes"); exit(0); }
		if(nIdexes >0) {
			if(fwrite(MOVI, sizeof(unsigned short), nIdexes, output) != nIdexes) { printf("Error while writing file indexarray"); exit(0); }
		}

		if(fwrite("VERT",4, 1, output) != 1) { printf("Error while writing file nbraches ID"); exit(0); }
		wsize = sizeof(int) + sizeof(float) * 3 * nVertices;
		if(fwrite(&wsize, sizeof(int), 1, output) != 1) { printf("Error while writing file wsize"); }
		if(fwrite(&nVertices, sizeof(int), 1, output) != 1) { printf("Error while writing file nVertices"); exit(0); }
		if(nVertices >0) {
			if(fwrite(MOVT, sizeof(float)*3, nVertices, output) != nVertices) { printf("Error while writing file vectors"); exit(0); }
		}

		if(LiquEx_size != 0)
		{
			int LIQU_h[] = {0x5551494C,LiquEx_size+8,hlq_xverts,hlq_yverts};// "LIQU"	
			fwrite(LIQU_h,4,4,output);
			fwrite(LiquEx,4,LiquEx_size/4,output);	
			delete [] LiquEx;
		}

		return nTriangles;
	} 	else {
		//printf("Convert GroupWmo...\n");
		//-------GRP -------------------------------------
		fwrite(&liquflags,sizeof(uint32),1,output); 
		char GRP[] = "GRP ";
		fwrite(GRP,1,4,output);
		int k = 0;
		int moba_batch = moba_size/12;
		MobaEx = new int[moba_batch*4];
		for(int i=8; i<moba_size; i+=12)
		{
			MobaEx[k++] = MOBA[i];
		}
		delete [] MOBA;
		int moba_size_grp = moba_batch*4+4;
		fwrite(&moba_size_grp,4,1,output); 
		fwrite(&moba_batch,4,1,output);
		fwrite(MobaEx,4,k,output);
		delete [] MobaEx;

		//-------INDX------------------------------------
		//-------MOPY--------
		int n = 0;
		int j = 0;
		MopyEx = new char[mopy_size];
		IndexExTr = new int[mopy_size];
		for (int i=0; i<mopy_size; i+=2)
		{
            // Skip no collision triangles
            if ((int)MOPY[i]&WMO_MATERIAL_NO_COLLISION)
                continue;
            // Use only this triangles
            if ((int)MOPY[i]&(WMO_MATERIAL_HINT|WMO_MATERIAL_COLLIDE_HIT))
			{    
				MopyEx[n] = MOPY[i];
				MopyEx[(n+1)] = MOPY[(i+1)];
				IndexExTr[j] = i/2;
				j+=1;        
				n+=2;
			}    
		}
		MopyEx_size = n;
		IndexExTr_size = j;
		delete [] MOPY;
		delete [] MopyEx;

		//---------MOVI-----------
		MoviEx = new uint16[IndexExTr_size*3];
		int m = 0;
		for (int i=0; i<IndexExTr_size; i++)
		{
			int n = 0;
			n = IndexExTr[i]*3;
			for (int x=0; x<3; x++)
			{
				MoviEx[m] = MOVI[n];
				n++;
				m++;
			}
		}
		delete [] MOVI;

		MoviExSort = new uint16[IndexExTr_size*3];
		for(int y=0; y<IndexExTr_size*3; y++)
		{
			MoviExSort[y]=MoviEx[y];		
		}

		uint16 hold;
		for (int pass = 1; pass < IndexExTr_size*3; pass++)
		{
			for (int i=0; i < IndexExTr_size*3-1; i++)
			{
				if (MoviExSort[i] > MoviExSort[i+1]) 
				{
					hold = MoviExSort[i];
					MoviExSort[i] = MoviExSort[i+1];
					MoviExSort[i+1] = hold;
				}
				//double = 65535	
				else
					if (MoviExSort[i] == MoviExSort[i+1])
						MoviExSort[i+1] = 65535;	
			}
		}
		// double delet
		uint16 s = 0;
		for (int i=0; i < IndexExTr_size*3; i++)
		{
			if (MoviExSort[i]!=65535)
			{
				MoviExSort[s] = MoviExSort[i];
				s++;
			}
		}
		MovtExSort = new uint16[s];
		for (int i=0; i < s; i++)
		{
			MovtExSort[i] = MoviExSort[i];
		}

		for (int i=0; i < IndexExTr_size*3; i++)
		{
			uint16 b = MoviEx[i];
			for (uint16 x = 0; x < s; x++)
			{
				if(MoviExSort[x] == b)
				{

					MoviEx[i] = x;
					break;
				}
			}	

		}
		int INDX[] = {0x58444E49,IndexExTr_size*6+4,IndexExTr_size*3};
		fwrite(INDX,4,3,output);
		fwrite(MoviEx,2,IndexExTr_size*3,output);

		delete [] MoviEx;
		delete [] MoviExSort;
		delete [] IndexExTr;

		//----------VERT---------
		//-----MOVT----------
		int d = 0;
		MovtEx = new float[s*3];
		for (uint16 i=0; i<s; i++)
		{
			int c=0;//!!!!data in MovtExSort[i] more uint16 in great group wmo files!!!!
			c = MovtExSort[i]*3;
			for (int y=0; y<3; y++)
			{
				MovtEx[d] = MOVT[c];
				c++;
				d++;
			}
		}
		int VERT[] = {0x54524556,d*4+4,d*4/12};// "VERT"
		fwrite(VERT,4,3,output);
		fwrite(MovtEx,4,d,output);	
		//------LIQU------------------------
		if(LiquEx_size != 0)
		{
			int LIQU_h[] = {0x5551494C,LiquEx_size+8,hlq_xverts,hlq_yverts};// "LIQU"	
			fwrite(LIQU_h,4,4,output);
			fwrite(LiquEx,4,LiquEx_size/4,output);	
			delete [] LiquEx;
		}

		delete [] MOVT;
		delete [] MovtEx;
		delete [] MovtExSort;

		//---------------------------------------------	
		return IndexExTr_size;
	}
}

WMOGroup::~WMOGroup()
{
}

WMOInstance::WMOInstance(MPQFile &f,const char* WmoInstName,const char*MapName, FILE *pDirfile)
{
    pos = Vec3D(0,0,0);

    float ff[3];
    f.read(&id, 4);
    f.read(ff,12);
    pos = Vec3D(ff[0],ff[1],ff[2]);
    f.read(ff,12);
    rot = Vec3D(ff[0],ff[1],ff[2]);
    f.read(ff,12);
    pos2 = Vec3D(ff[0],ff[1],ff[2]);
    f.read(ff,12);
    pos3 = Vec3D(ff[0],ff[1],ff[2]);
    f.read(&d2,4);
    f.read(&d3,4);

    doodadset = (d2 & 0xFFFF0000) >> 16;

    int realx1 = (int) ((float) pos2.x / 533.333333f);
    int realy1 = (int) ((float) pos2.z / 533.333333f);
    int realx2 = (int) ((float) pos3.x / 533.333333f);
    int realy2 = (int) ((float) pos3.z / 533.333333f);

    if(realx1 < 0)
    {
        realx1 +=20; realx2+=20;
    }
    if(realy1 < 0)
    {
        realy1 +=20; realy2+=20;
    } // hack to prevent neg. values

    //-----------add_in _dir_file----------------

    char tempname[512];
    //  const char dirname[] = "buildings\\dir";

    sprintf(tempname, "buildings\\%s", WmoInstName);
    FILE *input;
    input = fopen(tempname, "r+b");
    if(!input)
    {
        return;
    }
    fseek(input, 8, SEEK_SET); // get the correct no of vertices
    int nVertices;
    fread(&nVertices, sizeof (int), 1, input);
    fclose(input);
    if(nVertices == 0)
    {
        return;
    }

    /*  FILE *dirfile;
    dirfile = fopen(dirname, "ab");
    if(!dirfile)
    {
    printf("Can't open dirfile!'%s'\n");
    return;
    }
    */
    float x,z;
    x = pos.x;
    z = pos.z;
    if(x==0 && z == 0)
    { x = 533.33333f*32; z = 533.33333f*32; }
    fprintf(pDirfile,"%s/%s %f,%f,%f_%f,%f,%f 1.0 %d %d %d,%d %d\n",
        MapName,
        WmoInstName,
        (float) x, (float) pos.y, (float) z,
        (float) rot.x, (float) rot.y, (float) rot.z,
        nVertices,
        realx1, realy1,
        realx2, realy2
        );

    // fclose(dirfile);
}





