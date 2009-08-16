/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_SYSTEM_H
#define SC_SYSTEM_H

extern DatabaseType TScriptDB;

#define TEXT_SOURCE_RANGE -1000000                          //the amount of entries each text source has available

struct ScriptPointMove
{
    uint32 uiCreatureEntry;
    uint32 uiPointId;
    float  fX;
    float  fY;
    float  fZ;
    uint32 uiWaitTime;
};

struct StringTextData
{
    uint32 uiSoundId;
    uint8  uiType;
    uint32 uiLanguage;
    uint32 uiEmote;
};

#define pSystemMgr SystemMgr::Instance()

class SystemMgr
{
    public:
        SystemMgr();
        ~SystemMgr() {}

        static SystemMgr& Instance();

        //Maps and lists
        typedef UNORDERED_MAP<int32, StringTextData> TextDataMap;
        typedef UNORDERED_MAP<uint32, std::vector<ScriptPointMove> > PointMoveMap;

        //Database
        void LoadVersion();
        void LoadScriptTexts();
        void LoadScriptTextsCustom();
        void LoadScriptWaypoints();

        //Retrive from storage
        StringTextData const* GetTextData(int32 uiTextId) const
        {
            TextDataMap::const_iterator itr = m_mTextDataMap.find(uiTextId);

            if (itr == m_mTextDataMap.end())
                return NULL;

            return &itr->second;
        }

        std::vector<ScriptPointMove> const &GetPointMoveList(uint32 uiCreatureEntry) const
        {
            static std::vector<ScriptPointMove> vEmpty;

            PointMoveMap::const_iterator itr = m_mPointMoveMap.find(uiCreatureEntry);

            if (itr == m_mPointMoveMap.end())
                return vEmpty;

            return itr->second;
        }

    protected:
        TextDataMap     m_mTextDataMap;                     //additional data for text strings
        PointMoveMap    m_mPointMoveMap;                    //coordinates for waypoints
};

#endif
