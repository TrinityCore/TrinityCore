#ifndef _MODELCONTAINERVIEW_H
#define _MODELCONTAINERVIEW_H

#include <G3D/G3DAll.h>
#include <G3D/System.h>
#include "ModelContainer.h"
#include "DebugCmdLogger.h"
#include "vmapmanager.h"




namespace VMAP
{
	//==========================================


	//==========================================

	class ModelContainerView : 
		public G3D::GApp
	{
	private:
        SkyRef              iSky;
        LightingRef         iLighting;
        SkyParameters       iSkyParameters;

		VARAreaRef iVARAreaRef;
		Table<std::string , VAR*> iTriVarTable;
		Table<std::string , Array<int> > iTriIndexTable;

		VARAreaRef iVARAreaRef2;
        VAR iTriDebugVar;
        Array<Vector3> iVTriDebugArray;
        Array<int> iTriDebugArray;

        //Array<int> iLineIndexArray;

		GApp* i_App;
		CommandFileRW iCommandFileRW;
		Array<Command> iCmdArray;
		int iCurrCmdIndex;

		VMapManager* iVMapManager;

		Vector3 iPos1;
		Vector3 iPos2;
		Color3 iColor;
		bool iDrawLine;
		int iInstanceId;
        bool iPosSent;
        Array<Command> iPrevLoadCommands;
	private:
		Vector3 convertPositionToMangosRep(float x, float y, float z) const;

	public:
		ModelContainerView(const G3D::GApp::Settings& settings);

		~ModelContainerView(void);

		void addModelContainer(const std::string& pName,const ModelContainer* pModelContainer);
		void removeModelContainer(const std::string& pName, const ModelContainer* pModelContainer);
		void setViewPosition(const Vector3& pPosition);

		void onGraphics(RenderDevice* rd, Array<PosedModelRef> &posed3D, Array<PosedModel2DRef> &posed2D);
        virtual void onInit();
        void init();
		void cleanup();
		void onUserInput(UserInput* ui);

		void fillRenderArray(const SubModel& pSm,Array<TriangleBox> &pArray, const TreeNode* pTreeNode);
		void fillVertexAndIndexArrays(const SubModel& pSm, Array<Vector3>& vArray, Array<int>& iArray);

		bool loadAndShowTile(int pMapId, int x, int y);
		void showMap(int pMapId, int x, int y);

		void showMap(MapTree* mt, std::string dirFileName);
		bool loadAndShowTile(int pMapId);


		void processCommand();

	};

	//==========================================
	//==========================================
}

#endif
