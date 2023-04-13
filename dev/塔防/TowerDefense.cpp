//From:https://uiwow.com/thread-3858-1-1.html?_dsign=64a2a99e
//由现有图片转化、修正
//图片1
void CastDef aultSpell(Unit* target)
{
    if (!target)
        return;
    if (me->GetDist ance(target->GetPositionX 0), target->GetPosit ionY(), target->GetPositionZ() > 8)
        me->SetFacingTo(target->Get0rientation());

    if (MobIsAirMob && instance->GetGuardIsAntiAir(target->GetGUID() && MobSpellId) //空中单位可以被反空单位攻击
        me->CastSpell(target, MobSpellId, true) :
    else if (!MobIsAirMob && instance->GetGuardIsAntiGround(target->GetGUID()) && MobSpel1Id) //地面生物可以被地面生物攻击
        me->CastSpell(target, MobSpellId, true) :
}

void DanageDealt(Unit* target, uint32& damage, DanageEffectType damageType)
{
    if (damageType != SPELL_DIRECT_DAIMAGE) //这里原本是法术伤害,改为指定伤害，防止和其他伤害控制系统冲突
        return;
        damage = 0:
}

void DamageTaken(Unit* attacker, uint32& damage)
{
    me->SetFlag(UNIT_FIELD_FLAGS, UNII_FLAG_IMMUNE_T0_PC) : //玩家不能攻击
}
bool GuardIsInDistance(Unit* guard)
{
    if (!guard)
        return false;
    if (WaveIsRurning()) {
        if (me->GetDistance(guard->GetPositionX()), guard->GetPositionY(), guard->GetPositionZ()) <= MobAttackDistance)
        return true:
    }
    return false;
}

bool IsCasting()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return false;
}

void UpdateAI(const uint32 diff)
{

    //图片2
}
}

/*
玩家点击TD_ ITEM():, 开始计数，每秒向玩家播放一次，持续3秒，到0后会话被设置为true
*/
void TowerDefenseInstanceScript::TowerDefenseMapInstanceScript::StartNextWave(uint32 timer)
{
    uint32 WaveId = GetCurrent WaveId();
    SetCurrentWaveId(++waveId);
    SetEventStatus(TD_EVENT_STATUS_RUNING);
    Events.ScheduleEvent(TD_EVENT_DATA_START_MUSIC_TIMER, 200000) : //音乐
        Events.ScheduleEvent(TD_EVENT_DATA_START_WAVE_TIMER, timer); //会话倒计时
    RecordlLog(" TowerDefense:会话ID: [%u] 将在%毫秒内运行."，GetCurrentWaveId(), timer) :
}

void TowerDefenseInstanceScript::TowerDefenseMapInstanceScript::StartEvent(P1ayer* player, uint32 Action)
{
    if (!player || player->IsInCombat() || player->GetSession()->isLoging0ut() || player->GetGroup()) {
        ChatHandler(player).SendSysMessage(ID_SYSTEM_MSG_CANNOT_STARI_DUE) :
            return;
        if (GetPlayer() && player->GetGUIDLow() != GetPlayer()->GetGUIDLow()) {
            ChatHandler(player).SendSysMessage(TD_SYSTEM_MSG_CANNOT_START_ALREADY);
            return;
        }
        else {
            SetPlayer(player);
        }
        if (!player)
            return;

        player->P1ayDirectSound(ID_STARTEVENT_MUSIC, player);//播放声音
        SetupEventData();
        player->AddItem(34131, 1); //给玩家添加物品
        player->SaveToDB() : //保存玩家数据到数据库
            player->TeleportTo(GellapId(), GetPSpawnX()， GetPSpawnY()， GetPSpawnZ()， GetPSpawno()); // teleport to starting location
        SetEventStatus(TD_EVENT_STATUS_TELEPORT);
        switch (Action)
        {
        case 1051: //难度控制简单
            SetEventMode(TD_EVENT_MODE_EASY);
            SendMessageToPlayer(TD_SYSTEM_MSG_STARTED_EVENT_EASY);
            //等待用户启动会话
            break;
        case 1052: //难度控制困难
            SetEvenMode(TD_EVENT_MODE_HARD);
            SendessageToPlayer(TD_SYSTEM_MSG_STARTED_EVENT_HARD);
            StartNextWave(30000); // 30内开始会话
            break;
        case 1053: //难度控制变态
            SetEventMode(TD_EVENT_MODE_EXTREME) :
            SendMessageToPlayer(ID_SYSTEM_MSG_STARTED_EVENT_EXTREME) :
            StartNextWave(1000); //马上开始会话.
            break;
