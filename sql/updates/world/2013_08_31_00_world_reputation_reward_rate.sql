525f381dce8e9f480399832200a1a0736bd9d62d
 src/server/game/AI/EventAI/CreatureEventAIMgr.cpp  |  4 +-
 src/server/game/AI/SmartScripts/SmartScriptMgr.cpp |  2 +-
 src/server/game/Entities/Player/Player.cpp         | 42 +++++++-------
 src/server/game/Globals/ObjectMgr.cpp              | 50 ++++++++---------
 src/server/game/Handlers/QuestHandler.cpp          |  2 +-
 src/server/game/Quests/QuestDef.cpp                | 29 +++++-----
 src/server/game/Quests/QuestDef.h                  | 65 +++++++++++++---------
 7 files changed, 102 insertions(+), 92 deletions(-)

diff --git a/src/server/game/AI/EventAI/CreatureEventAIMgr.cpp b/src/server/game/AI/EventAI/CreatureEventAIMgr.cpp
index f77499f..c6bfd33 100644
--- a/src/server/game/AI/EventAI/CreatureEventAIMgr.cpp
+++ b/src/server/game/AI/EventAI/CreatureEventAIMgr.cpp
@@ -507,7 +507,7 @@ void CreatureEventAIMgr::LoadCreatureEventAI_Scripts()
                 case ACTION_T_QUEST_EVENT:
                     if (Quest const* qid = sObjectMgr->GetQuestTemplate(action.quest_event.questId))
                     {
-                        if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
+                        if (!qid->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
                             TC_LOG_ERROR(LOG_FILTER_SQL, "CreatureEventAI:  Event %u Action %u. SpecialFlags for quest entry %u does not include |2, Action will not have any effect.", i, j+1, action.quest_event.questId);
                     }
                     else
@@ -541,7 +541,7 @@ void CreatureEventAIMgr::LoadCreatureEventAI_Scripts()
                 case ACTION_T_QUEST_EVENT_ALL:
                     if (Quest const* qid = sObjectMgr->GetQuestTemplate(action.quest_event_all.questId))
                     {
-                        if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
+                        if (!qid->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
                             TC_LOG_ERROR(LOG_FILTER_SQL, "CreatureEventAI:  Event %u Action %u. SpecialFlags for quest entry %u does not include |2, Action will not have any effect.", i, j+1, action.quest_event_all.questId);
                     }
                     else
diff --git a/src/server/game/AI/SmartScripts/SmartScriptMgr.cpp b/src/server/game/AI/SmartScripts/SmartScriptMgr.cpp
index 2e0fd22..081599c 100644
--- a/src/server/game/AI/SmartScripts/SmartScriptMgr.cpp
+++ b/src/server/game/AI/SmartScripts/SmartScriptMgr.cpp
@@ -696,7 +696,7 @@ bool SmartAIMgr::IsEventValid(SmartScriptHolder& e)
         case SMART_ACTION_CALL_GROUPEVENTHAPPENS:
             if (Quest const* qid = sObjectMgr->GetQuestTemplate(e.action.quest.quest))
             {
-                if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
+                if (!qid->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
                 {
                     TC_LOG_ERROR(LOG_FILTER_SQL, "SmartAIMgr: Entry %d SourceType %u Event %u Action %u SpecialFlags for Quest entry %u does not include FLAGS_EXPLORATION_OR_EVENT(2), skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.action.quest.quest);
                     return false;
diff --git a/src/server/game/Entities/Player/Player.cpp b/src/server/game/Entities/Player/Player.cpp
index 9b38117..b1ee724 100644
--- a/src/server/game/Entities/Player/Player.cpp
+++ b/src/server/game/Entities/Player/Player.cpp
@@ -14921,7 +14921,7 @@ bool Player::CanCompleteQuest(uint32 quest_id)
 
         if (q_status.Status == QUEST_STATUS_INCOMPLETE)
         {
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
             {
                 for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
                 {
@@ -14930,7 +14930,7 @@ bool Player::CanCompleteQuest(uint32 quest_id)
                 }
             }
 
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_KILL | QUEST_TRINITY_FLAGS_CAST | QUEST_TRINITY_FLAGS_SPEAKTO))
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO))
             {
                 for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; i++)
                 {
@@ -14942,14 +14942,14 @@ bool Player::CanCompleteQuest(uint32 quest_id)
                 }
             }
 
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_PLAYER_KILL))
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL))
                 if (qInfo->GetPlayersSlain() != 0 && q_status.PlayerCount < qInfo->GetPlayersSlain())
                     return false;
 
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT) && !q_status.Explored)
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT) && !q_status.Explored)
                 return false;
 
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_TIMED) && q_status.Timer == 0)
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && q_status.Timer == 0)
                 return false;
 
             if (qInfo->GetRewOrReqMoney() < 0)
@@ -14976,7 +14976,7 @@ bool Player::CanCompleteRepeatableQuest(Quest const* quest)
     if (!CanTakeQuest(quest, false))
         return false;
 
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
         for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
             if (quest->RequiredItemId[i] && quest->RequiredItemCount[i] && !HasItemCount(quest->RequiredItemId[i], quest->RequiredItemCount[i]))
                 return false;
@@ -15002,7 +15002,7 @@ bool Player::CanRewardQuest(Quest const* quest, bool msg)
         return false;
 
     // prevent receive reward with quest items in bank
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
     {
         for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
         {
@@ -15079,19 +15079,19 @@ void Player::AddQuest(Quest const* quest, Object* questGiver)
     questStatusData.Status = QUEST_STATUS_INCOMPLETE;
     questStatusData.Explored = false;
 
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
     {
         for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
             questStatusData.ItemCount[i] = 0;
     }
 
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_KILL | QUEST_TRINITY_FLAGS_CAST | QUEST_TRINITY_FLAGS_SPEAKTO))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO))
     {
         for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
             questStatusData.CreatureOrGOCount[i] = 0;
     }
 
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_PLAYER_KILL))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL))
         questStatusData.PlayerCount = 0;
 
     GiveQuestSourceItem(quest);
@@ -15106,7 +15106,7 @@ void Player::AddQuest(Quest const* quest, Object* questGiver)
             GetReputationMgr().SetVisible(factionEntry);
 
     uint32 qtime = 0;
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_TIMED))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
     {
         uint32 limittime = quest->GetLimitTime();
 
@@ -15347,7 +15347,7 @@ void Player::FailQuest(uint32 questId)
             SetQuestSlotState(log_slot, QUEST_STATE_FAIL);
         }
 
-        if (quest->HasFlag(QUEST_TRINITY_FLAGS_TIMED))
+        if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
         {
             QuestStatusData& q_status = m_QuestStatus[questId];
 
@@ -15643,7 +15643,7 @@ bool Player::SatisfyQuestConditions(Quest const* qInfo, bool msg)
 
 bool Player::SatisfyQuestTimed(Quest const* qInfo, bool msg)
 {
-    if (!m_timedquests.empty() && qInfo->HasFlag(QUEST_TRINITY_FLAGS_TIMED))
+    if (!m_timedquests.empty() && qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
     {
         if (msg)
         {
@@ -16003,7 +16003,7 @@ uint16 Player::GetReqKillOrCastCurrentCount(uint32 quest_id, int32 entry)
 
 void Player::AdjustQuestReqItemCount(Quest const* quest, QuestStatusData& questStatusData)
 {
-    if (quest->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
     {
         for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
         {
@@ -16144,7 +16144,7 @@ void Player::ItemAddedQuestCheck(uint32 entry, uint32 count)
             continue;
 
         Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
-        if (!qInfo || !qInfo->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+        if (!qInfo || !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
             continue;
 
         for (uint8 j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
@@ -16182,7 +16182,7 @@ void Player::ItemRemovedQuestCheck(uint32 entry, uint32 count)
         Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
         if (!qInfo)
             continue;
-        if (!qInfo->HasFlag(QUEST_TRINITY_FLAGS_DELIVER))
+        if (!qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
             continue;
 
         for (uint8 j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
@@ -16254,7 +16254,7 @@ void Player::KilledMonsterCredit(uint32 entry, uint64 guid /*= 0*/)
         QuestStatusData& q_status = m_QuestStatus[questid];
         if (q_status.Status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid(GetMap()->GetDifficulty())))
         {
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_KILL) /*&& !qInfo->HasFlag(QUEST_TRINITY_FLAGS_CAST)*/)
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL) /*&& !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_CAST)*/)
             {
                 for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                 {
@@ -16305,7 +16305,7 @@ void Player::KilledPlayerCredit()
         QuestStatusData& q_status = m_QuestStatus[questid];
         if (q_status.Status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid(GetMap()->GetDifficulty())))
         {
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_PLAYER_KILL))
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL))
             {
                 uint32 reqkill = qInfo->GetPlayersSlain();
                 uint16 curkill = q_status.PlayerCount;
@@ -16345,7 +16345,7 @@ void Player::KillCreditGO(uint32 entry, uint64 guid)
 
         if (q_status.Status == QUEST_STATUS_INCOMPLETE)
         {
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_CAST) /*&& !qInfo->HasFlag(QUEST_TRINITY_FLAGS_KILL)*/)
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_CAST) /*&& !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL)*/)
             {
                 for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                 {
@@ -16399,7 +16399,7 @@ void Player::TalkedToCreature(uint32 entry, uint64 guid)
 
         if (q_status.Status == QUEST_STATUS_INCOMPLETE)
         {
-            if (qInfo->HasFlag(QUEST_TRINITY_FLAGS_KILL | QUEST_TRINITY_FLAGS_CAST | QUEST_TRINITY_FLAGS_SPEAKTO))
+            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO))
             {
                 for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                 {
@@ -18188,7 +18188,7 @@ void Player::_LoadQuestStatus(PreparedQueryResult result)
 
                 time_t quest_time = time_t(fields[3].GetUInt32());
 
-                if (quest->HasFlag(QUEST_TRINITY_FLAGS_TIMED) && !GetQuestRewardStatus(quest_id))
+                if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && !GetQuestRewardStatus(quest_id))
                 {
                     AddTimedQuest(quest_id);
 
diff --git a/src/server/game/Globals/ObjectMgr.cpp b/src/server/game/Globals/ObjectMgr.cpp
index 804967c..eaf2306 100644
--- a/src/server/game/Globals/ObjectMgr.cpp
+++ b/src/server/game/Globals/ObjectMgr.cpp
@@ -3765,11 +3765,11 @@ void ObjectMgr::LoadQuests()
         if (qinfo->GetQuestMethod() >= 3)
             TC_LOG_ERROR(LOG_FILTER_SQL, "Quest %u has `Method` = %u, expected values are 0, 1 or 2.", qinfo->GetQuestId(), qinfo->GetQuestMethod());
 
-        if (qinfo->Flags & ~QUEST_TRINITY_FLAGS_DB_ALLOWED)
+        if (qinfo->SpecialFlags & ~QUEST_SPECIAL_FLAGS_DB_ALLOWED)
         {
             TC_LOG_ERROR(LOG_FILTER_SQL, "Quest %u has `SpecialFlags` = %u > max allowed value. Correct `SpecialFlags` to value <= %u",
-                qinfo->GetQuestId(), qinfo->Flags  >> 20, QUEST_TRINITY_FLAGS_DB_ALLOWED >> 20);
-            qinfo->Flags &= QUEST_TRINITY_FLAGS_DB_ALLOWED;
+                qinfo->GetQuestId(), qinfo->SpecialFlags, QUEST_SPECIAL_FLAGS_DB_ALLOWED);
+            qinfo->SpecialFlags &= QUEST_SPECIAL_FLAGS_DB_ALLOWED;
         }
 
         if (qinfo->Flags & QUEST_FLAGS_DAILY && qinfo->Flags & QUEST_FLAGS_WEEKLY)
@@ -3778,30 +3778,30 @@ void ObjectMgr::LoadQuests()
             qinfo->Flags &= ~QUEST_FLAGS_DAILY;
         }
 
-        if (qinfo->Flags & QUEST_FLAGS_DAILY)
+        if (!(qinfo->SpecialFlags  & QUEST_SPECIAL_FLAGS_REPEATABLE))
         {
-            if (!(qinfo->Flags & QUEST_TRINITY_FLAGS_REPEATABLE))
+            if (!(qinfo->Flags & QUEST_FLAGS_DAILY))
             {
                 TC_LOG_ERROR(LOG_FILTER_SQL, "Daily Quest %u not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
-                qinfo->Flags |= QUEST_TRINITY_FLAGS_REPEATABLE;
+                qinfo->SpecialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
             }
         }
 
         if (qinfo->Flags & QUEST_FLAGS_WEEKLY)
         {
-            if (!(qinfo->Flags & QUEST_TRINITY_FLAGS_REPEATABLE))
+            if (!(qinfo->SpecialFlags  & QUEST_SPECIAL_FLAGS_REPEATABLE))
             {
                 TC_LOG_ERROR(LOG_FILTER_SQL, "Weekly Quest %u not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
-                qinfo->Flags |= QUEST_TRINITY_FLAGS_REPEATABLE;
+                qinfo->SpecialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
             }
         }
 
-        if (qinfo->Flags & QUEST_TRINITY_FLAGS_MONTHLY)
+        if (qinfo->SpecialFlags & QUEST_SPECIAL_FLAGS_MONTHLY)
         {
-            if (!(qinfo->Flags & QUEST_TRINITY_FLAGS_REPEATABLE))
+            if (!(qinfo->SpecialFlags  & QUEST_SPECIAL_FLAGS_REPEATABLE))
             {
                 TC_LOG_ERROR(LOG_FILTER_SQL, "Monthly quest %u not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
-                qinfo->Flags |= QUEST_TRINITY_FLAGS_REPEATABLE;
+                qinfo->SpecialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
             }
         }
 
@@ -4019,7 +4019,7 @@ void ObjectMgr::LoadQuests()
                     // no changes, quest can't be done for this requirement
                 }
 
-                qinfo->SetFlag(QUEST_TRINITY_FLAGS_DELIVER);
+                qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER);
 
                 if (!sObjectMgr->GetItemTemplate(id))
                 {
@@ -4080,7 +4080,7 @@ void ObjectMgr::LoadQuests()
             {
                 // In fact SpeakTo and Kill are quite same: either you can speak to mob:SpeakTo or you can't:Kill/Cast
 
-                qinfo->SetFlag(QUEST_TRINITY_FLAGS_KILL | QUEST_TRINITY_FLAGS_CAST | QUEST_TRINITY_FLAGS_SPEAKTO);
+                qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO);
 
                 if (!qinfo->RequiredNpcOrGoCount[j])
                 {
@@ -4290,12 +4290,12 @@ void ObjectMgr::LoadQuests()
         if (qinfo->ExclusiveGroup)
             mExclusiveQuestGroups.insert(std::pair<int32, uint32>(qinfo->ExclusiveGroup, qinfo->GetQuestId()));
         if (qinfo->LimitTime)
-            qinfo->SetFlag(QUEST_TRINITY_FLAGS_TIMED);
+            qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED);
         if (qinfo->RequiredPlayerKills)
-            qinfo->SetFlag(QUEST_TRINITY_FLAGS_PLAYER_KILL);
+            qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL);
     }
 
-    // check QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT for spell with SPELL_EFFECT_QUEST_COMPLETE
+    // check QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT for spell with SPELL_EFFECT_QUEST_COMPLETE
     for (uint32 i = 0; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
     {
         SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(i);
@@ -4315,12 +4315,12 @@ void ObjectMgr::LoadQuests()
             if (!quest)
                 continue;
 
-            if (!quest->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
+            if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
             {
-                TC_LOG_ERROR(LOG_FILTER_SQL, "Spell (id: %u) have SPELL_EFFECT_QUEST_COMPLETE for quest %u, but quest not have flag QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT. Quest flags must be fixed, quest modified to enable objective.", spellInfo->Id, quest_id);
+                TC_LOG_ERROR(LOG_FILTER_SQL, "Spell (id: %u) have SPELL_EFFECT_QUEST_COMPLETE for quest %u, but quest not have flag QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT. Quest flags must be fixed, quest modified to enable objective.", spellInfo->Id, quest_id);
 
                 // this will prevent quest completing without objective
-                const_cast<Quest*>(quest)->SetFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT);
+                const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT);
             }
         }
     }
@@ -4491,13 +4491,13 @@ void ObjectMgr::LoadScripts(ScriptsType type)
                     continue;
                 }
 
-                if (!quest->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
+                if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
                 {
-                    TC_LOG_ERROR(LOG_FILTER_SQL, "Table `%s` has quest (ID: %u) in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u, but quest not have flag QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT in quest flags. Script command or quest flags wrong. Quest modified to require objective.",
+                    TC_LOG_ERROR(LOG_FILTER_SQL, "Table `%s` has quest (ID: %u) in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u, but quest not have flag QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT in quest flags. Script command or quest flags wrong. Quest modified to require objective.",
                         tableName.c_str(), tmp.QuestExplored.QuestID, tmp.id);
 
                     // this will prevent quest completing without objective
-                    const_cast<Quest*>(quest)->SetFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT);
+                    const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT);
 
                     // continue; - quest objective requirement set and command can be allowed
                 }
@@ -5390,12 +5390,12 @@ void ObjectMgr::LoadQuestAreaTriggers()
             continue;
         }
 
-        if (!quest->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
+        if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
         {
-            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `areatrigger_involvedrelation` has record (id: %u) for not quest %u, but quest not have flag QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT. Trigger or quest flags must be fixed, quest modified to require objective.", trigger_ID, quest_ID);
+            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `areatrigger_involvedrelation` has record (id: %u) for not quest %u, but quest not have flag QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT. Trigger or quest flags must be fixed, quest modified to require objective.", trigger_ID, quest_ID);
 
             // this will prevent quest completing without objective
-            const_cast<Quest*>(quest)->SetFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT);
+            const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT);
 
             // continue; - quest modified to required objective and trigger can be allowed.
         }
diff --git a/src/server/game/Handlers/QuestHandler.cpp b/src/server/game/Handlers/QuestHandler.cpp
index e51d87c..e032c82 100644
--- a/src/server/game/Handlers/QuestHandler.cpp
+++ b/src/server/game/Handlers/QuestHandler.cpp
@@ -450,7 +450,7 @@ void WorldSession::HandleQuestLogRemoveQuest(WorldPacket& recvData)
 
             if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
             {
-                if (quest->HasFlag(QUEST_TRINITY_FLAGS_TIMED))
+                if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
                     _player->RemoveTimedQuest(questId);
 
                 if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
diff --git a/src/server/game/Quests/QuestDef.cpp b/src/server/game/Quests/QuestDef.cpp
index 7345dca..f2e80bd 100644
--- a/src/server/game/Quests/QuestDef.cpp
+++ b/src/server/game/Quests/QuestDef.cpp
@@ -60,7 +60,7 @@ Quest::Quest(Field* questRecord)
     SourceItemIdCount = questRecord[35].GetUInt8();
     SourceSpellid = questRecord[36].GetUInt32();
     Flags = questRecord[37].GetUInt32();
-    uint32 SpecialFlags = questRecord[38].GetUInt8();
+    SpecialFlags = questRecord[38].GetUInt8();
     RewardTitleId = questRecord[39].GetUInt8();
     RequiredPlayerKills = questRecord[40].GetUInt8();
     RewardTalents = questRecord[41].GetUInt8();
@@ -139,30 +139,29 @@ Quest::Quest(Field* questRecord)
 
     //int32 WDBVerified = questRecord[140].GetInt32();
 
-    Flags |= SpecialFlags << 20;
-    if (Flags & QUEST_TRINITY_FLAGS_AUTO_ACCEPT)
+    if (SpecialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
         Flags |= QUEST_FLAGS_AUTO_ACCEPT;
 
-    m_reqitemscount = 0;
-    m_reqCreatureOrGOcount = 0;
-    m_rewitemscount = 0;
-    m_rewchoiceitemscount = 0;
+    _reqItemsCount = 0;
+    _reqCreatureOrGOcount = 0;
+    _rewItemsCount = 0;
+    _rewChoiceItemsCount = 0;
 
-    for (int i=0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
+    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
         if (RequiredItemId[i])
-            ++m_reqitemscount;
+            ++_reqItemsCount;
 
-    for (int i=0; i < QUEST_OBJECTIVES_COUNT; ++i)
+    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
         if (RequiredNpcOrGo[i])
-            ++m_reqCreatureOrGOcount;
+            ++_reqCreatureOrGOcount;
 
-    for (int i=0; i < QUEST_REWARDS_COUNT; ++i)
+    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
         if (RewardItemId[i])
-            ++m_rewitemscount;
+            ++_rewItemsCount;
 
-    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
+    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
         if (RewardChoiceItemId[i])
-            ++m_rewchoiceitemscount;
+            ++_rewChoiceItemsCount;
 }
 
 uint32 Quest::XPValue(Player* player) const
diff --git a/src/server/game/Quests/QuestDef.h b/src/server/game/Quests/QuestDef.h
index b279665..88a4ddf 100644
--- a/src/server/game/Quests/QuestDef.h
+++ b/src/server/game/Quests/QuestDef.h
@@ -75,7 +75,7 @@ enum QuestShareMessages
     QUEST_PARTY_MSG_NOT_IN_PARTY            = 10
 };
 
-enum __QuestTradeSkill
+enum QuestTradeSkill
 {
     QUEST_TRSKILL_NONE           = 0,
     QUEST_TRSKILL_ALCHEMY        = 1,
@@ -106,7 +106,7 @@ enum QuestStatus
     MAX_QUEST_STATUS
 };
 
-enum __QuestGiverStatus
+enum QuestGiverStatus
 {
     DIALOG_STATUS_NONE                     = 0,
     DIALOG_STATUS_UNAVAILABLE              = 1,
@@ -146,22 +146,28 @@ enum QuestFlags
     QUEST_FLAGS_OBJ_TEXT                = 0x00040000,   // use Objective text as Complete text
     QUEST_FLAGS_AUTO_ACCEPT             = 0x00080000,   // The client recognizes this flag as auto-accept. However, NONE of the current quests (3.3.5a) have this flag. Maybe blizz used to use it, or will use it in the future.
 
+    // ... 4.x added flags up to 0x80000000 - all unknown for now
+};
+
+enum QuestSpecialFlags
+{
+    QUEST_SPECIAL_FLAGS_NONE                 = 0x000,
     // Trinity flags for set SpecialFlags in DB if required but used only at server
-    QUEST_TRINITY_FLAGS_REPEATABLE           = 0x00100000,   // Set by 1 in SpecialFlags from DB
-    QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT = 0x00200000,   // Set by 2 in SpecialFlags from DB (if reequired area explore, spell SPELL_EFFECT_QUEST_COMPLETE casting, table `*_script` command SCRIPT_COMMAND_QUEST_EXPLORED use, set from script)
-    QUEST_TRINITY_FLAGS_AUTO_ACCEPT          = 0x00400000,  // Set by 4 in SpecialFlags in DB if the quest is to be auto-accepted.
-    QUEST_TRINITY_FLAGS_DF_QUEST             = 0x00800000,  // Set by 8 in SpecialFlags in DB if the quest is used by Dungeon Finder.
-    QUEST_TRINITY_FLAGS_MONTHLY              = 0x01000000,  // Set by 16 in SpecialFlags in DB if the quest is reset at the begining of the month
-    QUEST_TRINITY_FLAGS_CAST                 = 0x02000000,  // Set by 32 in SpecialFlags in DB if the quest requires RequiredOrNpcGo killcredit but NOT kill (a spell cast)
-    
-    QUEST_TRINITY_FLAGS_DB_ALLOWED = 0xFFFFF | QUEST_TRINITY_FLAGS_REPEATABLE | QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT | QUEST_TRINITY_FLAGS_AUTO_ACCEPT | QUEST_TRINITY_FLAGS_DF_QUEST | QUEST_TRINITY_FLAGS_MONTHLY | QUEST_TRINITY_FLAGS_CAST,
+    QUEST_SPECIAL_FLAGS_REPEATABLE           = 0x001,   // Set by 1 in SpecialFlags from DB
+    QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT = 0x002,   // Set by 2 in SpecialFlags from DB (if required area explore, spell SPELL_EFFECT_QUEST_COMPLETE casting, table `FECT_QUEST_COMPLETE casting, table `*_script` command SCRIPT_COMMAND_QUEST_EXPLORED use, set from script)
+    QUEST_SPECIAL_FLAGS_AUTO_ACCEPT          = 0x004,   // Set by 4 in SpecialFlags in DB if the quest is to be auto-accepted.
+    QUEST_SPECIAL_FLAGS_DF_QUEST             = 0x008,   // Set by 8 in SpecialFlags in DB if the quest is used by Dungeon Finder.
+    QUEST_SPECIAL_FLAGS_MONTHLY              = 0x010,   // Set by 16 in SpecialFlags in DB if the quest is reset at the begining of the month
+    QUEST_SPECIAL_FLAGS_CAST                 = 0x020,   // Set by 32 in SpecialFlags in DB if the quest requires RequiredOrNpcGo killcredit but NOT kill (a spell cast)
+    // room for more custom flags
 
-    // Trinity flags for internal use only
-    QUEST_TRINITY_FLAGS_DELIVER              = 0x04000000,   // Internal flag computed only
-    QUEST_TRINITY_FLAGS_SPEAKTO              = 0x08000000,   // Internal flag computed only
-    QUEST_TRINITY_FLAGS_KILL                 = 0x10000000,   // Internal flag computed only
-    QUEST_TRINITY_FLAGS_TIMED                = 0x20000000,   // Internal flag computed only
-    QUEST_TRINITY_FLAGS_PLAYER_KILL          = 0x40000000    // Internal flag computed only
+    QUEST_SPECIAL_FLAGS_DB_ALLOWED = QUEST_SPECIAL_FLAGS_REPEATABLE | QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT | QUEST_SPECIAL_FLAGS_AUTO_ACCEPT | QUEST_SPECIAL_FLAGS_DF_QUEST | QUEST_SPECIAL_FLAGS_MONTHLY | QUEST_SPECIAL_FLAGS_CAST,
+
+    QUEST_SPECIAL_FLAGS_DELIVER              = 0x080,   // Internal flag computed only
+    QUEST_SPECIAL_FLAGS_SPEAKTO              = 0x100,   // Internal flag computed only
+    QUEST_SPECIAL_FLAGS_KILL                 = 0x200,   // Internal flag computed only
+    QUEST_SPECIAL_FLAGS_TIMED                = 0x400,   // Internal flag computed only
+    QUEST_SPECIAL_FLAGS_PLAYER_KILL          = 0x800    // Internal flag computed only
 };
 
 struct QuestLocale
@@ -191,6 +197,9 @@ class Quest
         bool HasFlag(uint32 flag) const { return (Flags & flag) != 0; }
         void SetFlag(uint32 flag) { Flags |= flag; }
 
+        bool HasSpecialFlag(uint32 flag) const { return (SpecialFlags & flag) != 0; }
+        void SetSpecialFlag(uint32 flag) { SpecialFlags |= flag; }
+
         // table data accessors:
         uint32 GetQuestId() const { return Id; }
         uint32 GetQuestMethod() const { return Method; }
@@ -246,18 +255,18 @@ class Quest
         uint32 GetPointOpt() const { return PointOption; }
         uint32 GetIncompleteEmote() const { return EmoteOnIncomplete; }
         uint32 GetCompleteEmote() const { return EmoteOnComplete; }
-        bool   IsRepeatable() const { return Flags & QUEST_TRINITY_FLAGS_REPEATABLE; }
+        bool   IsRepeatable() const { return SpecialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE; }
         bool   IsAutoAccept() const;
         bool   IsAutoComplete() const;
         uint32 GetFlags() const { return Flags; }
         bool   IsDaily() const { return Flags & QUEST_FLAGS_DAILY; }
         bool   IsWeekly() const { return Flags & QUEST_FLAGS_WEEKLY; }
-        bool   IsMonthly() const { return Flags & QUEST_TRINITY_FLAGS_MONTHLY; }
+        bool   IsMonthly() const { return SpecialFlags & QUEST_SPECIAL_FLAGS_MONTHLY; }
         bool   IsSeasonal() const { return (ZoneOrSort == -QUEST_SORT_SEASONAL || ZoneOrSort == -QUEST_SORT_SPECIAL || ZoneOrSort == -QUEST_SORT_LUNAR_FESTIVAL || ZoneOrSort == -QUEST_SORT_MIDSUMMER || ZoneOrSort == -QUEST_SORT_BREWFEST || ZoneOrSort == -QUEST_SORT_LOVE_IS_IN_THE_AIR || ZoneOrSort == -QUEST_SORT_NOBLEGARDEN) && !IsRepeatable(); }
         bool   IsDailyOrWeekly() const { return Flags & (QUEST_FLAGS_DAILY | QUEST_FLAGS_WEEKLY); }
         bool   IsRaidQuest(Difficulty difficulty) const;
         bool   IsAllowedInRaid(Difficulty difficulty) const;
-        bool   IsDFQuest() const { return Flags & QUEST_TRINITY_FLAGS_DF_QUEST; }
+        bool   IsDFQuest() const { return SpecialFlags & QUEST_SPECIAL_FLAGS_DF_QUEST; }
         uint32 CalculateHonorGain(uint8 level) const;
 
         // multiple values
@@ -280,10 +289,10 @@ class Quest
         uint32 OfferRewardEmote[QUEST_EMOTE_COUNT];
         uint32 OfferRewardEmoteDelay[QUEST_EMOTE_COUNT];
 
-        uint32 GetReqItemsCount() const { return m_reqitemscount; }
-        uint32 GetReqCreatureOrGOcount() const { return m_reqCreatureOrGOcount; }
-        uint32 GetRewChoiceItemsCount() const { return m_rewchoiceitemscount; }
-        uint32 GetRewItemsCount() const { return m_rewitemscount; }
+        uint32 GetReqItemsCount() const { return _reqItemsCount; }
+        uint32 GetReqCreatureOrGOcount() const { return _reqCreatureOrGOcount; }
+        uint32 GetRewChoiceItemsCount() const { return _rewChoiceItemsCount; }
+        uint32 GetRewItemsCount() const { return _rewItemsCount; }
 
         typedef std::vector<int32> PrevQuests;
         PrevQuests prevQuests;
@@ -292,10 +301,10 @@ class Quest
 
         // cached data
     private:
-        uint32 m_reqitemscount;
-        uint32 m_reqCreatureOrGOcount;
-        uint32 m_rewchoiceitemscount;
-        uint32 m_rewitemscount;
+        uint32 _reqItemsCount;
+        uint32 _reqCreatureOrGOcount;
+        uint32 _rewChoiceItemsCount;
+        uint32 _rewItemsCount;
 
         // table data
     protected:
@@ -354,6 +363,8 @@ class Quest
         uint32 PointOption;
         uint32 EmoteOnIncomplete;
         uint32 EmoteOnComplete;
+
+        uint32 SpecialFlags; // custom flags, not sniffed/WDB
 };
 
 struct QuestStatusData
