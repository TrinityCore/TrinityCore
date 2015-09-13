#ifdef HW2COMPILE_SCRIPT

#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "ScriptMgr.h"


/*

Elenco comandi Az:   

TIPO1:

lvl 1 =  mute/unmute/parla/sussurra/urla/txtem

lvl 2 =  paralizza/rilascia/listapr/salvatutti/suono/tempo...

lvl 3 =  uccidi /resuscita / espelli / espellitutti 

lvl 4 =  ricarica_actrpg / chatlog_on/chatlog_off / hv_lanciaspell /mantello /divinityon /divinityoff /trans /pulizia_characters

TIPO2:

lvl 1 =  segui_pet/segui_area/segui_pos/fermo/ritorna/ostile/cammina_qui 

lvl 2 =  summon/emote_area

lvl 3 =  dio/resist/risana       
                   

*/

class hw2system_commandscript : public CommandScript
{
public:
    hw2system_commandscript() : CommandScript("hw2system_commandscript") { }

    ChatCommand* GetCommands() const OVERRIDE
    {
        static ChatCommand hw2systemCommandTable[] =
        {
            { "run",            SEC_ADMINISTRATOR,  false,  &Handlehw2Command,      "", NULL },
            { NULL,             0,                  false,  NULL,                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "hw2",    SEC_PLAYER,  false, NULL,            "", hw2systemCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool Handlehw2Command(ChatHandler* handler, char const* args)
    {
        Player *autore= handler->GetSession()->GetPlayer();

            if (!autore)
                return false;

            if(!*args)
            {
                sHw2->Hw2SendSysMessage(autore,"Comando errato o non inserito, digita .az comandi per visualizzare i comandi disponibili");
                return true;
            }

            std::string argstr = strtok((char*)args, " ");
            char* stringa = strtok(NULL, ""); 

            if (argstr == "comandi")
            {


                sHw2->Hw2SendSysMessage(autore," ");
                sHw2->Hw2SendSysMessage(autore,"I comandi speciali (tipo0) sono:");
                sHw2->Hw2SendSysMessage(autore," ");
                sHw2->Hw2SendSysMessage(autore,"lvl0: rpg_profilo <> rpg_precettore");


                if (autore->hw2Player->AccLvl[0]>0)
                {
                    sHw2->Hw2SendSysMessage(autore," ");
                    sHw2->Hw2SendSysMessage(autore,"I comandi speciali (tipo1) sono:");
                    sHw2->Hw2SendSysMessage(autore," ");
                    sHw2->Hw2SendSysMessage(autore," lvl1: mute <> unmute <> parla <> sussurra <> urla <> txtem");

                    if (autore->hw2Player->AccLvl[0]>=2)
                    {
                        sHw2->Hw2SendSysMessage(autore," lvl2: paralizza <> rilascia <> listapr <> salvatutti <> suono <> tempo");
                        if (autore->hw2Player->AccLvl[0]>=3) 
                        {
                            sHw2->Hw2SendSysMessage(autore," lvl3: uccidi <> resuscita <> espelli <> espellitutti ");
                            if (autore->hw2Player->AccLvl[0]>=4)
                                sHw2->Hw2SendSysMessage(autore," lvl4: conf <> rpg_ricarica <> chatlog_on <> chatlog_off <> mantello <> divinityon  <> divinityoff <> trans <> pulizia_characters(fare prima un backup! usarlo cautamente)");
                            else
                                sHw2->Hw2SendSysMessage(autore,"lvl superiore: accesso ai comandi non disponibile");

                        } else sHw2->Hw2SendSysMessage(autore,"lvl superiore: accesso ai comandi non disponibile");

                    } else sHw2->Hw2SendSysMessage(autore,"lvl superiore: accesso ai comandi non disponibile");

                } else sHw2->Hw2SendSysMessage(autore,"Comandi tipo 1: accesso ai comandi non disponibile");

                if (autore->hw2Player->AccLvl[1]>0)
                {
                    sHw2->Hw2SendSysMessage(autore," ");
                    sHw2->Hw2SendSysMessage(autore,"I comandi speciali (tipo2) sono:");
                    sHw2->Hw2SendSysMessage(autore," ");
                     sHw2->Hw2SendSysMessage(autore," lvl1: segui_pet <> segui_pos <> segui_area<> fermo <> ritorna <> ostile <> cammina_qui");

                    if (autore->hw2Player->AccLvl[1]>=2)
                    {
                         sHw2->Hw2SendSysMessage(autore," lvl2: summon <> guardian <> emote_area <> rpg_crediti <> rpg_identity <> rpg_identity_byname <> rpg_profilo_byname");
                         if (autore->hw2Player->AccLvl[1]>=3) 
                             sHw2->Hw2SendSysMessage(autore," lvl3: dio <> resist <> risana <> rpg_punti <> rpg_mod_precettore");
                         else
                             sHw2->Hw2SendSysMessage(autore,"lvl superiore: accesso ai comandi non disponibile");

                    }else sHw2->Hw2SendSysMessage(autore,"lvl superiore: accesso ai comandi non disponibile");

                }else sHw2->Hw2SendSysMessage(autore,"Comandi tipo 2: accesso ai comandi non disponibile");

              return true;
            }



        //########################################################################################## 
        // 
        // COMANDI PUBBLICI
        //
        //##########################################################################################

            if (argstr=="rpg_profilo")
            {
                Player* SelPl = getSelectedPlayer();

                if (SelPl)
                    sHw2->RpgVisualizzaProfilo(autore,SelPl);

                return true;
            }

            if (argstr=="rpg_precettore")
            {

                ObjectGuid guid  = autore->GetSelectionGuid();
                Player* SelPl=NULL;
                if (guid.GetCounter()!=0)
                {
                    SelPl=sObjectMgr.GetPlayer(guid);
                }

                char* nome = strtok(stringa, " ");

                guid=ObjectGuid(); // reset variabile

                guid=sHw2->HandleFindPlayer(nome,autore,SelPl);

                if (guid.GetCounter()==0)
                { 
                    sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: Devi selezionare un giocatore oppure inserirne il nome(opzionale) per settarlo come precettore");
                    sHw2->Hw2SendSysMessage(autore,".az rpg_precettore <nomeplayer> (opzionale se il player e' gia' selezionato)");
                    return false; 
                } 

                sHw2->RpgSetSupervisor(autore->GetObjectGuid(),guid,autore);
                return true;
            }




        //##########################################################################################
        //	CONTROLLI COMANDI NON PUBBLICI
        //##########################################################################################


        if (autore->hw2Player->AccLvl[0]<=0 && autore->hw2Player->AccLvl[1]<=0) return false; // se l'account non e' presente nella lista non accedera' ai prossimi comandi


        //########################################################################################## 
        // 
        // TIPO 1
        //
        //##########################################################################################


            //##########################################################################################
            //	LIVELLO 1
            //##########################################################################################

        if (autore->hw2Player->AccLvl[0]>=1)
        {

            if (argstr == "mute")
            {
                if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,"Specifica il nome del pg seguito dal tempo della durata del mute in minuti "); return false; }
                HandleMuteCommand(stringa);
                return true;
            }

            if (argstr == "unmute")
            {
                if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,"Specifica il nome del pg"); return false; }
                HandleUnmuteCommand(stringa);
                return true;
            }

            if (argstr == "parla")
            {
                if (!stringa || !strcmp(stringa," ")) return false;
                HandleNpcSayCommand(stringa);
                getSelectedCreature()->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                return true;
            }

            if (argstr == "sussurra")
            {    
               if (!stringa || !strcmp(stringa," ")) return false;
               HandleNpcWhisperCommand(stringa);
               return true;
            }

            if (argstr == "urla")
            {   
               if (!stringa || !strcmp(stringa," ")) return false;
               HandleNpcYellCommand(stringa);
               getSelectedCreature()->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
               return true;
            }

            if (argstr == "txtem")
            {       
               if (!stringa || !strcmp(stringa," ")) return false;
               HandleNpcTextEmoteCommand(stringa);
               return true;
            }

            //##########################################################################################
            //	LIVELLO 2
            //##########################################################################################

                    if (autore->hw2Player->AccLvl[0] >= 2)
                    {
                        if (argstr == "paralizza")
                        {	

                            std::string name;
                            Player* player;
                            char* TargetName = stringa; //get entered #name

                            if (!TargetName) //if no #name entered use target
                            {
                                player = getSelectedPlayer();
                                if (player) //prevent crash with creature as target
                                {   
                                   name = player->GetName();
                                   normalizePlayerName(name);
                                }
                            }
                            else // if #name entered
                            {
                                name = TargetName;
                                normalizePlayerName(name);
                                player = sObjectMgr.GetPlayer(name.c_str()); //get player by #name
                            }

                            //effect
                            if ((player) && (!(player==autore)))
                            {
                                sHw2->Hw2SendSysMessage(autore,"%s paralizzato",name.c_str());

                                //stop combat + unattackable + duel block + stop some spells
                                //TODO: Test this a bit more ingame
                                player->setFaction(35);
                                player->CombatStop();
                                if(player->IsNonMeleeSpellCasted(true))
                                player->InterruptNonMeleeSpells(true);
                                player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                player->SetUInt32Value(PLAYER_DUEL_TEAM, 1);

                                //if player class = hunter || warlock remove pet if alive
                                if((player->getClass() == CLASS_HUNTER) || (player->getClass() == CLASS_WARLOCK))
                                {
                                    if(Pet* pet = player->GetPet())
                                    {
                                        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
                                        // not let dismiss dead pet
                                        if(pet->isAlive())
                                            player->RemovePet(PET_SAVE_NOT_IN_SLOT);
                                    }
                                }

                                //stop movement and disable spells
                                uint32 spellID = 9454; //2647;
                                SpellEntry const *spellInfo = sSpellStore.LookupEntry( spellID );
                                if(spellInfo) //TODO: Change the duration of the aura to -1 instead of 5000000
                                {
                                    for(uint32 i = 0;i<3;i++)
                                    {
                                        uint8 eff = spellInfo->Effect[i];
                                        if (eff>=TOTAL_SPELL_EFFECTS)
                                            continue;

                                        SpellAuraHolder *new_holder = CreateSpellAuraHolder(spellInfo, player, NULL);

                                        if(eff == SPELL_EFFECT_APPLY_AREA_AURA_PARTY)
                                        {
                                            Aura *Aur = new AreaAura(spellInfo, SpellEffectIndex(i),NULL, NULL, player, NULL);
                                            new_holder->AddAura(Aur,SpellEffectIndex(i));
                                        }
                                        else if (eff == SPELL_EFFECT_APPLY_AURA || eff == SPELL_EFFECT_PERSISTENT_AREA_AURA)
                                        {
                                            Aura *Aur = CreateAura(spellInfo, SpellEffectIndex(i), NULL, NULL, player, NULL);
                                            new_holder->AddAura(Aur,SpellEffectIndex(i));
                                        }
                                    }
                                }
                                //save player
                                player->SaveToDB();
                                    }

                            if (!player)
                            {
                                sHw2->Hw2SendSysMessage(autore,"Nessun player selezionato");
                                return true;
                            }

                            if (player==autore)
                            {
                                sHw2->Hw2SendSysMessage(autore,"Non puoi paralizzare te stesso!");
                                return true;
                            }
                         return true;
                        }

                        if (argstr == "rilascia")
                        {
                            std::string name;
                            Player* player;
                            char* TargetName = stringa; //get entered #name
                            if (!TargetName) //if no #name entered use target
                            {
                                player = getSelectedPlayer();
                                if (player) //prevent crash with creature as target
                                {   
                                   name = player->GetName();
                                }
                            }

                            else // if #name entered
                            {
                                name = TargetName;
                                normalizePlayerName(name);
                                player = sObjectMgr.GetPlayer(name.c_str()); //get player by #name
                            }

                            //effect
                            if (player)
                            {
                                sHw2->Hw2SendSysMessage(autore,"Player %s liberato",name.c_str());

                                //Reset player faction + allow combat + allow duels
                                player->setFactionForRace(player->getRace());
                                player->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                                //allow movement and spells
                                uint32 spellID = 9454; //2647;
                                player->RemoveAurasDueToSpell(spellID);

                                //save player
                                player->SaveToDB();
                            }

                            if (!player)
                            {
                                sHw2->Hw2SendSysMessage(autore,"Nessun player selezionato");
                                return true;
                            }
                          return true;
                         }

                         if (argstr == "listapr")
                         {
                             //Get names from DB
                            QueryResult *result = CharacterDatabase.PQuery("SELECT characters.name FROM `characters` LEFT JOIN `character_aura` ON (characters.guid = character_aura.guid) WHERE character_aura.spell = 9454");
                            if(!result)
                            {
                                sHw2->Hw2SendSysMessage(autore,"Nessun player nella lista");
                                return true;
                            }
                            //Header of the names
                            sHw2->Hw2SendSysMessage(autore,"Lista:");

                            //Output of the results
                            do
                            {
                                Field *fields = result->Fetch();
                                std::string fplayers = fields[0].GetCppString();
                                sHw2->Hw2SendSysMessage(autore,"- %s",fplayers.c_str());
                            } while (result->NextRow());

                            delete result;
                            return true;
                        }


                        if (argstr == "suono")
                        {
                         if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,"scegli il suono"); return false; }
                           HandleDebugPlaySoundCommand(stringa);
                           return true;
                        }

                        if (argstr == "tempo")
                        {
                         if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,"scegli le condizioni atmosferiche"); return false; }
                           HandleChangeWeatherCommand(stringa);
                           return true;
                        }

                        if (argstr == "salvatutti")
                        {
                           ObjectAccessor::Instance().SaveAllPlayers(); // salva tutti
                           return true;
                        }

            //##########################################################################################
            //	LIVELLO 3
            //##########################################################################################

                                if (autore->hw2Player->AccLvl[0]>=3)
                                {

                                    if (argstr == "espelli")
                                    {
                                       if (!stringa || !strcmp(stringa," ")) stringa=NULL;    
                                       HandleKickPlayerCommand(stringa);
                                       return true;
                                    }

                                    if (argstr == "espellitutti")
                                    {
                                        if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,"scegli il l'acclvl da espellere"); return false; }
                                       HandleServerPLimitCommand(stringa);
                                       return true;
                                    }


                                    if (argstr == "uccidi")
                                    {	    
                                        Player *plr=NULL;

                                        if (!stringa || !strcmp(stringa," ")) 
                                        { plr = getSelectedPlayer(); 
                                          if (!plr) { sHw2->Hw2SendSysMessage(autore,"Seleziona un player o digita il nome"); return false; }
                                        }
                                        else plr = sObjectMgr.GetPlayer(stringa);

                                        if (!plr) 
                                        {
                                            sHw2->Hw2SendSysMessage(autore,"Il player %s non e' online oppure non esiste.",stringa);
                                            return true;
                                        }

                                        if(plr->isDead())
                                        {
                                            sHw2->Hw2SendSysMessage(autore,"Il player %s e' gia' morto.",plr->GetName());
                                        } 
                                        else 
                                        {
                                            plr->SetUInt32Value(UNIT_FIELD_HEALTH, 0); // Die, insect
                                            plr->KillPlayer();
                                            sHw2->Hw2SendSysMessage(plr,"Tu sei stato ucciso da un GM con un comando amministrativo"); //, m_session->GetPlayer()->GetName()
                                            sHw2->Hw2SendSysMessage(autore,"Uccisione avvenuta");
                                        }
                                            return true;
                                    }

                                    if (argstr == "resuscita")
                                    {		 
                                        if (!stringa) { stringa=""; sHw2->Hw2SendSysMessage(autore,"Inserendo un nome e' possibile resuscitare a distanza"); }
                                             HandleReviveCommand(stringa);
                                             return true;
                                    }

                                 }
                     }
        }



        //##########################################################################################
        //
        //          TIPO 2
        //
        //##########################################################################################

            //##########################################################################################
            //	LIVELLO 1
            //##########################################################################################

        if (autore->hw2Player->AccLvl[1]>=1)
        {

            if (argstr == "segui_pet")
            {
                Creature * creature = getSelectedCreature();
                if(!creature) return false;
                //      creature->RemoveAurasDueToSpell(39258);
                creature->clearUnitState(UNIT_STAT_ROOT);

                creature->GetMotionMaster()->MoveFollow(autore,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE);
                creature->SetSpeedRate(MOVE_WALK,    autore->GetSpeedRate(MOVE_WALK),true);
                creature->SetSpeedRate(MOVE_RUN,     autore->GetSpeedRate(MOVE_RUN),true);
                creature->SetSpeedRate(MOVE_SWIM,    autore->GetSpeedRate(MOVE_SWIM),true);
                creature->SetSpeedRate(MOVE_FLIGHT,     autore->GetSpeedRate(MOVE_FLIGHT),true);
                if (autore->m_movementInfo.GetMovementFlags()==SPLINEFLAG_WALKMODE)
                    sHw2->Hw2SendSysMessage(autore,"Seguimi! (MODALITA' WALK)");
                else
                    sHw2->Hw2SendSysMessage(autore,"Seguimi! (MODALITA' RUN)");
                return true;
            }

            if (argstr == "segui_pos")
            {
                Creature * creature = getSelectedCreature();
                if(!creature) return false;
                //      creature->RemoveAurasDueToSpell(39258);
                creature->clearUnitState(UNIT_STAT_ROOT);

                creature->GetMotionMaster()->MoveFollow(autore,autore->GetDistance(creature),autore->GetAngle(creature));
                creature->SetSpeedRate(MOVE_WALK,    autore->GetSpeedRate(MOVE_WALK),true);
                creature->SetSpeedRate(MOVE_RUN,     autore->GetSpeedRate(MOVE_RUN),true);
                creature->SetSpeedRate(MOVE_SWIM,    autore->GetSpeedRate(MOVE_SWIM),true);
                creature->SetSpeedRate(MOVE_FLIGHT,     autore->GetSpeedRate(MOVE_FLIGHT),true);
                if (autore->HasMovementFlag(MOVEFLAG_WALK_MODE))
                {
                    creature->SetWalk(true);
                    sHw2->Hw2SendSysMessage(autore,"Seguimi! (MODALITA' WALK)");
                }
                else
                {
                    creature->SetWalk(false);
                    sHw2->Hw2SendSysMessage(autore,"Seguimi! (MODALITA' RUN)");
                }
                return true;
            }

            if (argstr == "segui_area")
            {
                int distance=0;
                int type=0;
                strtok(stringa, " ");              // crea il token per la strtok successiva
                char* tipo = strtok(NULL, " ");

                if (tipo && stringa)
                {
                    distance = atoi(stringa);
                    type = atoi(tipo);
                }

                if (distance<=0 || type<=0) 
                { 
                  sHw2->Hw2SendSysMessage(autore,"Devi inserire una distanza in yard (non troppo alta) e il tipo di creatura da selezionare (1: amiche 2: nemiche 3: entrambe");
                  sHw2->Hw2SendSysMessage(autore,"Sintassi: .az segui_area <yard> <tipocreatura>");
                  return false; 
                } 

                std::list<Unit *> targets,Tmerge;
                switch(type)
                {
                    case 1:
                        targets = sHw2->SelectNearbyTargets(autore,1,distance);
                    break;
                    case 2:
                        targets = sHw2->SelectNearbyTargets(autore,2,distance);
                    break;
                    case 3:
                        targets = sHw2->SelectNearbyTargets(autore,1,distance);
                        Tmerge = sHw2->SelectNearbyTargets(autore,2,distance);
                        targets.merge(Tmerge);
                    break;
                    default:
                        sHw2->Hw2SendSysMessage(autore,"Tipo creatura non valida");
                        return false;
                    break;
                }

                if(targets.empty()) 
                {	 sHw2->Hw2SendSysMessage(autore,"Nessuna creatura trovata nella distanza indicata e del tipo indicato");
                     return false;
                }

                std::list<Unit *>::const_iterator tcIter = targets.begin();
                for(uint32 i = 0; i < targets.size(); ++i)
                {
                    if ((Creature*)*tcIter && ((Unit*)*tcIter)->GetTypeId()!=TYPEID_PLAYER)
                    {
                        Creature * creature = (Creature*)*tcIter;
                        if(!creature) return false;
                        //      creature->RemoveAurasDueToSpell(39258);
                        creature->clearUnitState(UNIT_STAT_ROOT);
                        creature->GetMotionMaster()->MoveFollow(autore,autore->GetDistance(creature),autore->GetAngle(creature));
                        creature->SetSpeedRate(MOVE_WALK,    autore->GetSpeedRate(MOVE_WALK),true);
                        creature->SetSpeedRate(MOVE_RUN,     autore->GetSpeedRate(MOVE_RUN),true);
                        creature->SetSpeedRate(MOVE_SWIM,    autore->GetSpeedRate(MOVE_SWIM),true);
                        creature->SetSpeedRate(MOVE_FLIGHT,     autore->GetSpeedRate(MOVE_FLIGHT),true);
                        if (autore->HasMovementFlag(MOVEFLAG_WALK_MODE))
                            creature->SetWalk(true);
                        else
                            creature->SetWalk(false);
                    }
                     ++tcIter;
                }

                if (autore->HasMovementFlag(MOVEFLAG_WALK_MODE))
                    sHw2->Hw2SendSysMessage(autore,"Seguitemi tutti! (MODALITA' WALK)");
                else
                    sHw2->Hw2SendSysMessage(autore,"Seguitemi tutti! (MODALITA' RUN)");
                return true;
            }

            if (argstr == "fermo")
            {
                Creature * creature = getSelectedCreature();
                if(!creature) return false;
                creature->addUnitState(UNIT_STAT_ROOT);
            //	creature->CastSpell(creature,39258,true);
                sHw2->Hw2SendSysMessage(autore,"Fermati!");
                return true;
            }

            if (argstr == "ritorna")
            {
                Creature * creature = getSelectedCreature();
                if(!creature) return false;
                creature->clearUnitState(UNIT_STAT_ROOT);
                creature->clearUnitState(UNIT_STAT_FOLLOW);
                creature->GetMotionMaster()->Clear();
                creature->GetMotionMaster()->MoveTargetedHome();
                creature->SetSpeedRate(MOVE_WALK,    creature->GetSpeedRate(MOVE_WALK),true);
                creature->SetSpeedRate(MOVE_RUN,     creature->GetSpeedRate(MOVE_RUN),true);
                creature->SetSpeedRate(MOVE_SWIM,    creature->GetSpeedRate(MOVE_SWIM),true);
                creature->SetSpeedRate(MOVE_FLIGHT,     creature->GetSpeedRate(MOVE_FLIGHT),true);
                sHw2->Hw2SendSysMessage(autore,"Ritorna da dove sei venuto!");
                return true;
            }

            if (argstr == "cammina_qui")
            {
                float x,y,z;
                Creature * creature = getSelectedCreature();
                if(!creature) return false;
                creature->clearUnitState(UNIT_STAT_ROOT);
                creature->SetWalk(true);
                autore->GetClosePoint(x,y,z,autore->GetObjectBoundingRadius());
                float speed = (uint32)creature->GetDistance(autore) / ((float)((1000-creature->GetSpeed(MOVE_WALK))*((uint32)creature->GetDistance(autore))) * 0.001f);
                creature->MonsterMoveWithSpeed(autore->GetPositionX(),autore->GetPositionY(),autore->GetPositionZ(),speed,true);
                sHw2->Hw2SendSysMessage(autore,"cammina!");
                return true;
            }

            if (argstr == "ostile")
            {
                autore->SetGameMaster(false);
                autore->setFaction(0);
                m_session->SendNotification("Stato Ostile!");

                return true;
            }

            //##########################################################################################
            //	LIVELLO 2
            //##########################################################################################

                    if (autore->hw2Player->AccLvl[1]>=2) 
                    { 


                            if (argstr == "torneoesteso")
                            {
                                if (!stringa || !strcmp(stringa," ")) {sHw2->Hw2SendSysMessage(autore,".az torneoesteso on/off"); return false; }
                                std::string scelta = (char*)stringa;
                                if (scelta == "on") 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"Modalita' torneo esteso attivata");
                                    sHw2->Hw2Config(false,1,0,true); 
                                    return true; 
                                } 
                                else if (scelta == "off") 
                                {  
                                        sHw2->Hw2SendSysMessage(autore,"Modalita' torneo esteso disattivata");
                                        sHw2->Hw2Config(false,1,0,false);
                                        return true;
                                }

                                return false;
                            }

                            if (argstr == "torneo")
                            {
                                if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,".az torneo gruppo_on/off , raid_on/off , duel_on/off , ffa_on/off"); return false; }
                                std::string scelta = (char*)stringa;

                                if (scelta == "punti_on") 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"Possibilita' di guadagnare punti ed esperienza in gruppo attivata");
                                    sHw2->Hw2Config(false,1,1,true); 
                                    return true; 
                                } 
                                else if (scelta == "punti_off") 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"Possibilita' di guadagnare punti ed esperienza in gruppo disattivata");
                                    sHw2->Hw2Config(false,1,1,false); 
                                    return true; 
                                } 
                                else if (scelta == "gruppo_on") 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"Possibilita' di group attivata");
                                    sHw2->Hw2Config(false,1,2,true); 
                                    return true; 
                                } 
                                else if (scelta == "gruppo_off") 
                                {  
                                        sHw2->Hw2SendSysMessage(autore,"Possibilita' di group disattivata");
                                        sHw2->Hw2Config(false,1,2,false);
                                        return true;
                                }
                                else if (scelta == "raid_on") 
                                {
                                            sHw2->Hw2SendSysMessage(autore,"Possibilita' di raid e gruppo attivate");
                                            sHw2->Hw2Config(false,1,3,true);
                                            sHw2->Hw2Config(false,1,2,true);
                                            return true; 
                                }
                                else if (scelta == "raid_off") 
                                {
                                            sHw2->Hw2SendSysMessage(autore,"Possibilita' di raid e gruppo disattivate");
                                            sHw2->Hw2Config(false,1,3,false);
                                            sHw2->Hw2Config(false,1,2,false);
                                            return true;
                                }
                                else if (scelta == "duel_on") 
                                {
                                            sHw2->Hw2SendSysMessage(autore,"Possibilita' di duel attivata");
                                            sHw2->Hw2Config(false,1,4,true);
                                            return true;
                                }
                                else if (scelta == "duel_off") 
                                {
                                            sHw2->Hw2SendSysMessage(autore,"Possibilita' di duel disattivata");
                                            sHw2->Hw2Config(false,1,4,false);
                                            return true;
                                }
                                else if (scelta == "ffa_on") 
                                {
                                            sHw2->Hw2SendSysMessage(autore,"Modalita' PvP free for All sull'Hyjal attivata");
                                            sHw2->Hw2Config(false,1,5,true);
                                            return true;
                                }
                                else if (scelta == "ffa_off") 
                                {
                                            sHw2->Hw2SendSysMessage(autore,"Modalita' PvP free for All sull'Hyjal disattivata");
                                            sHw2->Hw2Config(false,1,5,false);
                                            return true;
                                }

                                 }


                                   if (argstr == "spoglia")
                                    {	

                                        std::string name;
                                        Player* player;
                                        char* TargetName = stringa; //get entered #name

                                        if (!TargetName) //if no #name entered use target
                                        {
                                            player = getSelectedPlayer();
                                            if (player) //prevent crash with creature as target
                                            {   
                                               name = player->GetName();
                                               normalizePlayerName(name);
                                            }
                                        }
                                        else // if #name entered
                                        {
                                            name = TargetName;
                                            normalizePlayerName(name);
                                            player = sObjectMgr.GetPlayer(name.c_str()); //get player by #name
                                        }

                                        //effect
                                        if ((player) && (!(player==m_session->GetPlayer())))
                                        {
                                            sHw2->DmSvuotaBorse(player);
                                            //save player
                                            player->SaveToDB();
                                        }

                                        if (!player)
                                        {
                                            sHw2->Hw2SendSysMessage(autore,"Nessun player selezionato");
                                            return true;
                                        }

                                        if (player==m_session->GetPlayer())
                                        {
                                            sHw2->Hw2SendSysMessage(autore,"Non puoi spogliare te stesso/a!");
                                            return true;
                                        }
                                    return true;

                                    }

                            if (argstr == "summon")
                            {
                                uint32 cEntry=0;

                                if(!autore) 
                                    return false; 

                                char* ID = stringa;
                                if (!ID){ sHw2->Hw2SendSysMessage(autore,"Devi inserire un ID di creatura."); return false; }

                                cEntry = atoi(ID);
                                if (cEntry==0) return false;

                                autore->SummonCreature(cEntry,autore->GetPositionX(),autore->GetPositionY(),autore->GetPositionZ(),PET_FOLLOW_ANGLE,TEMPSUMMON_CORPSE_DESPAWN,0);
                                                         sHw2->Hw2SendSysMessage(autore,"Evocazione Completata.");

                                return true;
                            }


                            if (argstr == "guardian")
                            {	
                                if(!autore) 
                                    return false; 

                                                        sHw2->Hw2SendSysMessage(autore,"select a creature to enable guardian flag, use -c option to enable custom script ");
                                                        sHw2->Hw2SendSysMessage(autore,"syntax: .az guardian <0/1> [options]");
                                                        sHw2->Hw2SendSysMessage(autore,"-c custom script enabled");

                                                        bool enabled = false;
                                                        bool customScript = false;

                                                        char* option1 = strtok(stringa, " ");
                                                        char* option2 = strtok(NULL, " ");

                                                        if (option1)
                                                                enabled = atoi(option1)>0;
                                                        if (option2)
                                                                customScript = strcmp(option2,"-c") == 0;


                                                        Creature * creature = getSelectedCreature();
                                                        if(!creature || !creature->IsInWorld()) return false;

                                                        if (enabled) {
                                                            //creature->setFaction(autore->getFaction());
                                                            creature->SetFactionTemporary(autore->getFaction(), TEMPFACTION_RESTORE_RESPAWN);
                                                            creature->azGuard = true;
                                                            if (customScript){
                                                                creature->customScriptID = GUARD1_ID;
                                                                creature->AIM_Initialize();
                                                                // creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GUARD);
                                                            }
                                                            sHw2->Hw2SendSysMessage(autore,"flag guardian enabled");
                                                        } else {
                                                            creature->azGuard = false;
                                                            creature->ClearTemporaryFaction();
                                                            creature->customScriptID = 0;
                                                            creature->AIM_Initialize();
                                                            creature->StopMoving();
                                                            creature->GetMotionMaster()->Clear();
                                                            sHw2->Hw2SendSysMessage(autore,"flag guardian disabled");
                                                        }

                                return true;
                            }

                                                if (argstr == "emote_area")
                            {
                                    int distance=0;
                                    int type=0;
                                    int emo=0; 
                                    strtok(stringa, " ");              // crea il token per la strtok successiva
                                    char* dist = strtok(NULL, " ");
                                    char* tipo = strtok(NULL, " ");

                                    if (dist && tipo && stringa)
                                    {
                                                                        emo=atoi(stringa);
                                        distance = atoi(dist);
                                        type = atoi(tipo);
                                    }

                                    if (distance<=0 || type<=0) 
                                    { 
                                      sHw2->Hw2SendSysMessage(autore,"Devi inserire il valore di un emote, una distanza in yard (non troppo alta) e il tipo di creatura da selezionare (1: amiche 2: nemiche 3: entrambe");
                                      sHw2->Hw2SendSysMessage(autore,"Sintassi: .az emote_area <emote> <yard> <tipocreatura>");
                                      return false; 
                                    } 

                                    std::list<Unit *> targets,Tmerge;
                                    switch(type)
                                    {
                                        case 1:
                                            targets = sHw2->SelectNearbyTargets(autore,1,distance);
                                        break;
                                        case 2:
                                            targets = sHw2->SelectNearbyTargets(autore,2,distance);
                                        break;
                                        case 3:
                                            targets = sHw2->SelectNearbyTargets(autore,1,distance);
                                            Tmerge = sHw2->SelectNearbyTargets(autore,2,distance);
                                            targets.merge(Tmerge);
                                        break;
                                        default:
                                            sHw2->Hw2SendSysMessage(autore,"Tipo creatura non valida");
                                            return false;
                                        break;
                                    }

                                    if(targets.empty()) 
                                    {	 
                                         sHw2->Hw2SendSysMessage(autore,"Nessuna creatura trovata nella distanza indicata e del tipo indicato");
                                         return false;
                                    }

                                    if (emo<=0) 
                                        sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: nessun id emote specificato");

                                    std::list<Unit *>::const_iterator tcIter = targets.begin();
                                                                for(uint32 i = 0; i < targets.size(); ++i)
                                    {
                                        if (((Unit*)*tcIter) && ((Unit*)*tcIter)->GetTypeId()!=TYPEID_PLAYER)
                                        {
                                            ((Unit*)*tcIter)->HandleEmoteCommand(emo);

                                        }
                                        ++tcIter;
                                    }
                                    return true;
                            }


                            if (argstr=="rpg_crediti")
                            {

                                if (!stringa || !strcmp(stringa," ")) 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: Devi inserire i punti credito e il nome(opzionale)");
                                    sHw2->Hw2SendSysMessage(autore,".az rpg_crediti <crediti> <nomeplayer> (opzionale se il player e' gia' selezionato)");
                                    return false; 
                                } 

                                                        int punti_cr=0;
                                ObjectGuid guid  = autore->GetSelectionGuid();
                                Player* SelPl=NULL;
                                if (guid.GetCounter()!=0)
                                {
                                    SelPl=sObjectMgr.GetPlayer(guid);
                                }

                                char* punti_credito = strtok(stringa, " ");              // crea il token per la strtok successiva
                                char* nome = strtok(NULL, " ");

                                if (punti_credito)
                                    punti_cr = atoi(punti_credito);

                                if (!punti_cr)
                                {
                                    sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: nessun punto credito assegnato");
                                    return false;
                                }

                                guid= sHw2->HandleFindPlayer(nome,autore,SelPl);
                                sHw2->RpgModificaPT(true,guid,punti_cr,0,false,SelPl);
                                sHw2->RpgAggiornaUpLine(guid,true,punti_cr);
                                return true;
                            }

                                                if (argstr=="rpg_identity")
                            {
                                if (!stringa || !strcmp(stringa," ")) 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: Devi inserire il testo con il quale si vuole identificare il player selezionato");
                                    sHw2->Hw2SendSysMessage(autore,".az rpg_identity <testo>");
                                    return false; 
                                } 

                                ObjectGuid guid  = autore->GetSelectionGuid();
                                if (guid.GetCounter()==0 )
                                {
                                    sHw2->Hw2SendSysMessage(autore,"ERRORE: Nessuna unita' selezionata");
                                    return false;
                                }

                                Player* SelPl = sObjectMgr.GetPlayer(guid);

                                guid=ObjectGuid(); //ridefinisce

                                if (SelPl)
                                {
                                    guid = SelPl->GetObjectGuid();
                                    sHw2->RpgModIdentity(guid,stringa,SelPl);
                                    return true;
                                }
                                else
                                {
                                  sHw2->Hw2SendSysMessage(autore,"ERRORE: Nessun player selezionato");
                                  return false;
                                }

                                return true;
                            }

                            if (argstr=="rpg_identity_byname")
                            {

                                ObjectGuid guid=ObjectGuid();

                                char* nome = strtok(stringa, " ");
                                char* identity = strtok(NULL, ""); // "" per prendere tutto il resto della stringa

                                if (!nome || !strcmp(nome," ") || !identity || !strcmp(identity," ")) 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"ERRORE: Devi inserire il nome del player e il testo con il quale si vuole identificarlo");
                                    sHw2->Hw2SendSysMessage(autore,".az rpg_identity_byname <nomeplayer> <testo>");
                                    return false; 
                                } 


                                guid = sHw2->HandleFindPlayer(nome,autore,NULL);
                                sHw2->RpgModIdentity(guid,identity,autore);
                                return true;
                            }


                            if (argstr=="rpg_profilo_byname")
                            {

                                if (!stringa || !strcmp(stringa," ")) 
                                { 
                                    sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: Devi inserirne il nome di un giocatore per visualizzarne il profilo, E' ASSOLUTAMENTE VIETATO USARE <FREQUENTEMENTE> IL COMANDO SU GIOCATORI NON IN LINEA");
                                    sHw2->Hw2SendSysMessage(autore,".az rpg_profilo_byname <nomeplayer>");
                                    return false; 
                                } 

                                char* nome = strtok(stringa, " ");

                                ObjectGuid 	guid = sHw2->HandleFindPlayer(nome,autore,NULL);

                                Player* SelPl=NULL;
                                if (guid.IsPlayer())
                                {
                                    SelPl=sObjectMgr.GetPlayer(guid);
                                } else return false;

                                if (SelPl)
                                    sHw2->RpgVisualizzaProfilo(autore,SelPl);
                                else	
                                    sHw2->RpgProfiloOffLine(guid,autore);

                                return true;
                            }


            //##########################################################################################
            //	LIVELLO 3
            //##########################################################################################

                                if (autore->hw2Player->AccLvl[1]>=3)
                                {

                                        if (argstr == "conf")
                                        {
                                            if (!stringa || !strcmp(stringa," ")) 
                                            { 
                                                uint16 i=0;
                                                sHw2->Hw2SendSysMessage(autore,".az conf <conf_id> <1/0>");
                                                sHw2->Hw2SendSysMessage(autore,"<conf_id> : l'id della configurazione da modificare");
                                                sHw2->Hw2SendSysMessage(autore,"<1/0> : attiva/disattiva la configurazione");
                                                sHw2->Hw2SendSysMessage(autore,"Le configurazioni disponibili sono le seguenti: ");
                                                for (i = 0 ; i != sHw2->ConfCount ; ++i )
                                                {
                                                    if (sHw2->AzConf[i])
                                                        sHw2->Hw2SendSysMessage(autore,"Conf %u (attivata): %s ",i,sHw2->ConfDef[i].c_str());
                                                    else
                                                        sHw2->Hw2SendSysMessage(autore,"Conf %u (disattivata): %s ",i,sHw2->ConfDef[i].c_str());
                                                }
                                                return false; 
                                            }

                                                int16 scelta = -1,conf = -1;
                                                bool sceltabl=false;

                                                // gestione conf
                                                char* confchr = strtok(stringa, " ");
                                                if (confchr)
                                                    conf=atoi(confchr);

                                                if (conf<0) return false;

                                                // gestione scelta
                                                char* sceltachr = strtok(NULL, " ");

                                                if (sceltachr)
                                                    scelta = atoi(sceltachr);

                                                if (scelta>=0 && scelta<=1) 
                                                    sceltabl=scelta;
                                                else return false;


                                                sHw2->Hw2Config(false,2,conf,sceltabl); 
                                                if (sceltabl) sHw2->Hw2SendSysMessage(autore,"Configurazione %u attivata ( %s )",conf,sHw2->ConfDef[conf].c_str());
                                                else sHw2->Hw2SendSysMessage(autore,"Configurazione %u disattivata ( %s )",conf,sHw2->ConfDef[conf].c_str());

                                                return true; 
                                         } 



                                        if (argstr == "resist")
                                        {
                                            if (!stringa || !strcmp(stringa," ")) 
                                            { 
                                                sHw2->Hw2SendSysMessage(autore,"devi inserire il numero di una resistenza da -2 a 6:");
                                                sHw2->Hw2SendSysMessage(autore,"NORMAL=0, HOLY = 1, FIRE = 2, NATURE = 3, FROST = 4, SHADOW = 5, ARCANE = 6,ARMOR = -2, TUTTE(tranne armor) = -1");
                                                return false; 
                                            }    


                                             strtok(stringa, " ");              // crea il token per la strtok successiva
                                             char* valore = strtok(NULL, " ");

                                             if (!valore) { sHw2->Hw2SendSysMessage(autore,"devi inserire il valore da assegnare alla resistenza"); return false; }

                                             int val = atoi(valore);
                                             int resistenza = atoi(stringa);

                                             if ( resistenza>6 || resistenza<-2) 
                                                 return false;

                                             sHw2->Hw2SendSysMessage(autore,"Eseguito! ( ricorda di non inserire valori <enormi>) ");

                                             if (resistenza == -1) 
                                             {
                                                for (int i = 0; i < MAX_SPELL_SCHOOL; i++)
                                                {
                                                    autore->SetResistance(SpellSchools(i), val);
                                                    autore->SetResistanceBuffMods(SpellSchools(i), true, 0.0f);
                                                    autore->SetResistanceBuffMods(SpellSchools(i), false, 0.0f);
                                                }
                                                return true;
                                             }

                                             if (resistenza == -2) { autore->SetArmor(val); return true; }

                                             autore->SetResistance(SpellSchools(resistenza), val);
                                             autore->SetResistanceBuffMods(SpellSchools(resistenza), true, (float)val);
                                             autore->SetResistanceBuffMods(SpellSchools(resistenza), false, (float)val);

                                            return true;
                                        }

                                        if (argstr == "dio")
                                        {

                                            autore->SetGameMaster(true);
                                            autore->setFactionForRace(autore->getRace());
                                            autore->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);

                                            sHw2->Hw2SendSysMessage(autore,"Devi cambiare zona per aggiornare il tuo stato");
                                            m_session->SendNotification("Ora sei un DIO!");

                                            return true;
                                        }

                                        if (argstr == "risana")
                                        {
                                            Player *autore= getSelectedPlayer();
                                            if(!autore){ sHw2->Hw2SendSysMessage(autore,"Seleziona un Player"); return false; }
                                            autore->ResurrectPlayer(1.0f);
                                            autore->RemoveAurasDueToSpell(15007);
                                            sHw2->Hw2SendSysMessage(autore,"Risanato e sciolta la maledizione della resurrezione...");
                                            return true;
                                        }

                                        if (argstr == "annuncio")
                                        {
                                            if (!stringa || !strcmp(stringa," ")) 
                                            { 
                                                sHw2->Hw2SendSysMessage(autore,"devi inserire un annuncio");
                                                return false; 
                                            }    
                                            HandleAnnounceCommand(stringa);
                                            return true;
                                        }

                                        if (argstr == "notifica")
                                        {
                                            if (!stringa || !strcmp(stringa," ")) 
                                            { 
                                                sHw2->Hw2SendSysMessage(autore,"devi inserire una notifica");
                                                return false; 
                                            }    
                                            HandleNotifyCommand(stringa);
                                            return true;
                                        }

                                        if (argstr=="rpg_punti")
                                        {

                                            if (!stringa || !strcmp(stringa," ")) 
                                            { 
                                                sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: Devi inserire i punti credito, i punti totale e il nome(opzionale)");
                                                sHw2->Hw2SendSysMessage(autore,".az mod_gdrpt <crediti> <totale> <nomeplayer> (opzionale se il player e' gia' selezionato)");
                                                return false; 
                                            } 

                                            int punti_cr=0,punti_tot=0;

                                            ObjectGuid guid  = autore->GetSelectionGuid();
                                            Player* SelPl=NULL;
                                            if (guid.IsPlayer())
                                            {
                                                SelPl=sObjectMgr.GetPlayer(guid);
                                            }

                                            char* punti_credito = strtok(stringa, " ");

                                            if (punti_credito)
                                                punti_cr = atoi(punti_credito);

                                            char* punti_totale = strtok(NULL, " ");
                                            if (punti_totale)
                                                punti_tot=atoi(punti_totale);

                                            char* nome = strtok(NULL, " ");

                                            guid= sHw2->HandleFindPlayer(nome,autore,SelPl);
                                            sHw2->RpgModificaPT(true,guid,punti_cr,punti_tot,false,SelPl);
                                            sHw2->RpgAggiornaUpLine(guid,true,punti_cr);
                                            return true;
                                        }

                                        if (argstr=="rpg_mod_precettore")
                                        {

                                            ObjectGuid guid_pl=ObjectGuid(),guid_sv=ObjectGuid();

                                            char* player = strtok(stringa, " ");
                                            char* supervisor = strtok(NULL, " "); // " " per prendere solo il nome

                                            if (!player || !strcmp(player," ") || !supervisor || !strcmp(supervisor," ")) 
                                            { 
                                                sHw2->Hw2SendSysMessage(autore,"ERRORE: Devi inserire il nome del player e del suo precettore");
                                                sHw2->Hw2SendSysMessage(autore,".az rpg_mod_precetto <nomeplayer> <nomeprecettore>");
                                                return false; 
                                            } 


                                            guid_pl= sHw2->HandleFindPlayer(player,autore,NULL);
                                            guid_sv= sHw2->HandleFindPlayer(supervisor,autore,NULL); 
                                            sHw2->RpgSetSupervisor(guid_pl,guid_sv,autore,true);
                                            return true;
                                        }

                                }
                    }
        }

        //##########################################################################################
        // COMANDI NASCOSTI, RITORNANO FALSE PER NON ESSERE MESSI A LOG
        //##########################################################################################

        if (autore->hw2Player->AccLvl[0]>=4)
        {

            if (argstr=="cambia_ora")
            {
                int type=0;
                char* tipo = strtok(stringa, " ");

                if (!tipo)
                    return false;

                tm localTm = *localtime(&sHw2->GetModGameTime());
                int ora = atoi(tipo);

                sHw2->newHr = localTm.tm_hour >= ora ? -1 * (localTm.tm_hour - ora) : ora - localTm.tm_hour;

                return true;

                /*tm localTm = *localtime(&sHw2->GetModGameTime());
                int now       = localTm.tm_hour;
                int diffHours = newHr - now;
                if(diffHours < 0)
                    diffHours *= -1;

                time_t newtime;
                for (uint8 i=0;i<=diffHours;i++)
                {
                    localTm.tm_hour = newHr >= now ? now + i : now - i;

                    // current day reset time
                    newtime = mktime(&localTm);
                    WorldPacket data(SMSG_LOGIN_SETTIMESPEED, 4 + 4 + 4);
                    data << uint32(secsToTimeBitFields(newtime));
                    data << (float)0.01666667f;                             // game speed
                    data << uint32(0);                                      // added in 3.1.2
                    sWorld.SendGlobalMessage( &data );
                }

                if (newtime)
                    sHw2->m_modGameTime = newtime; */

            }

            if (argstr=="creapet")
            {
                if(autore->GetPetGuid())
                return false;

                Creature * creatureTarget = getSelectedCreature();
                if(!creatureTarget) 
                    return false;

                if(creatureTarget->IsPet())
                    return false;

                CreatureCreatePos pos = CreatureCreatePos(autore, -autore->GetOrientation());

                Pet* pet = new Pet(MINI_PET);

                pet->Create(autore->GetMap()->GenerateLocalLowGuid(HIGHGUID_PET), pos,creatureTarget->GetCreatureInfo(), sObjectMgr.GeneratePetNumber());

                if(!pet)                                                // in versy specific state like near world end/etc.
                {
                    delete pet;
                    return false;
                }

                // kill original creature
                //creatureTarget->setDeathState(JUST_DIED);
                //creatureTarget->RemoveCorpse();
                //creatureTarget->SetHealth(0);                       // just for nice GM-mode view

                uint32 level = (creatureTarget->getLevel() < (autore->getLevel() - 5)) ? (autore->getLevel() - 5) : creatureTarget->getLevel();

                // prepare visual effect for levelup
                pet->SetUInt32Value(UNIT_FIELD_LEVEL, level - 1);
                pet->SetUInt32Value(UNIT_FIELD_LEVEL, level);

                pet->SetSummonPoint(pos);
                pet->GetMap()->Add((Creature*)pet);

                pet->SetOwnerGuid(autore->GetObjectGuid());
                pet->SetCreatorGuid(autore->GetObjectGuid());
                pet->setFaction(autore->getFaction());
                pet->AIM_Initialize();
                pet->InitPetCreateSpells();                         // e.g. disgusting oozeling has a create spell as critter...
                sHw2->Hw2SendSysMessage(autore,"minipet creato");
                return true;
            }

            if (argstr == "chatlog_on")
            {
                sHw2->Hw2SendSysMessage(autore,"[attenzione - comando critico!] Chat Log attivato");
                sLog.SetChatLog(true);
                return true;
            }

            if (argstr == "chatlog_off")
            {
                sHw2->Hw2SendSysMessage(autore,"[attenzione - comando critico!] Chat Log disattivato");
                sLog.SetChatLog(false);
                return true;
            }

            if (argstr == "divinityon")
            {
                autore->SetGameMaster(true);
                autore->setFactionForRace(autore->getRace());
                autore->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);
                m_session->SendNotification("Ora sei un DIO!");
                autore->getHostileRefManager().setOnlineOfflineState(true);
                sHw2->Hw2SendSysMessage(autore,"Devi cambiare zona per aggiornare il tuo stato");
                return false;
            }

            if (argstr == "divinityoff")
            {
                autore->SetGameMaster(false);
                m_session->SendNotification("Stato mortale");
                return false;
            }


            if (argstr == "mantello")
            {
                if (!stringa || !strcmp(stringa," ")) { sHw2->Hw2SendSysMessage(autore,"on/off"); return false; }
               HandleGMVisibleCommand(stringa);
               return false;
            }

            if (argstr == "trans")
            {
                if (!stringa || !strcmp(stringa," ")) return false; 
                HandleTeleCommand(stringa);
                return false;
            }

            if (argstr == "pulizia_characters") 
            {
                    sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: ASSICURATEVI DI AVER FATTO PRIMA UN BACKUP DEI CHARACTERS E DEGLI ACCOUNTS!!!!");

                    if (!stringa || !strcmp(stringa," ")) 
                    { 
                        sHw2->Hw2SendSysMessage(autore,"Devi inserire le 2 date: il <joindate> e il <last_login>, nel formato 'aaaa-mm-gg', preferibilmente con la differenza di un mese.");
                        sHw2->Hw2SendSysMessage(autore,"ES: < .az h_pulizia_characters 2008-1-31 2008-2-31 >   la procedura cancellera' tutti gli accounts che non loggano a partire dalla mezzanotte del tempo indicato nel last_login");
                        return false; 
                    }    

                    char* lastlogin = strtok(stringa, " ");              // crea il token per la strtok successiva
                    char* joindate  = strtok(NULL, " ");

                AccountMgr *AccMgr=NULL;
                uint32 i=0,j=0;

                // Uso il lastlogin per cancellare chi nn ha loggato dal tempo settato, e inoltre uso anche il joindate per evitare che si cancellino gli account nuovi non ancora loggati 
                // che sono appunto a 00-00-00 00:00:00 e quindi rientrano nella selezione

                QueryResult *AccResult = LoginDatabase.PQuery("SELECT `id` FROM `account` WHERE `joindate` <= '%s 00:00:00' AND `last_login` < '%s 00:00:00'",lastlogin,joindate);
                if(!AccResult)
                {
                     sHw2->Hw2SendSysMessage(autore,"Le 2 date non sono corrette oppure non ci sono accounts da cancellare!");
                     sHw2->Hw2SendSysMessage(autore,"devi inserire le 2 date: il <joindate> e il <last_login>, nel formato 'aaaa-mm-gg', preferibilmente con la differenza di un mese.");
                     sHw2->Hw2SendSysMessage(autore,"ES: < .az h_pulizia_characters 2008-1-31 2008-2-31 >   la procedura cancellera' tutti gli accounts che non loggano a partire dalla mezzanotte del tempo indicato nel last_login ");
                     return false;
                }

                do
                {
                        Field *fields = AccResult->Fetch();
                        uint32 AccId = fields[0].GetUInt32();

                        QueryResult *ChrResult = CharacterDatabase.PQuery("SELECT `guid` FROM `characters` WHERE `account` = %u OR `account` NOT IN (SELECT `id` FROM `realmd`.`account`)",AccId);
                        if(!ChrResult) return false; 
                        do
                        {
                                Field *fields = ChrResult->Fetch();
                                ObjectGuid CharGuid = ObjectGuid(HIGHGUID_PLAYER,fields[0].GetUInt32());

                                Player *player = sObjectMgr.GetPlayer(CharGuid);
                                if(player)
                                {
                                    player->GetSession()->KickPlayer();
                                }

                                Player::DeleteFromDB(CharGuid, AccId, true); 
                                i++;
                                //sHw2->Hw2SendSysMessage(autore,"Player (Guid: %u AccountId: %u) deleted",CharGuid,AccId);

                         } while( ChrResult->NextRow());

                        delete ChrResult;

                        int result = AccMgr->DeleteAccount(AccId);
                        if(result == -1)
                        {
                            sHw2->Hw2SendSysMessage(autore,"L'account %u non e' stato deletato (probably sql file format was updated)",AccId);
                        }
                        if(result == 1)
                        {
                            sHw2->Hw2SendSysMessage(autore,"L'account %u non esiste\r\n",AccId);
                        }
                        else if(result == 0)
                        {
                            //sHw2->Hw2SendSysMessage(autore,"account deletato: %u",AccId);
                            j++;
                        }

                 } while( AccResult->NextRow());

                delete AccResult;

                sHw2->Hw2SendSysMessage(autore,"Sono stati cancellati %u accounts e %u characters",j,i);
                return true;
            }

            if (argstr=="rpg_ricarica")
            {
                int store=-1;
                store=sHw2->InitList();
                if (store>=0) 
                {
                    sHw2->Hw2SendSysMessage(autore,"Caricate tabelle e %u definizioni per l'rpg action!",store);
                    return true;
                }else sHw2->Hw2SendSysMessage(autore,"Caricate tabelle - Nessuna definizione caricata!",store);

                return true;
            }

            if (argstr=="massive_pdump")
            {

                sHw2->Hw2SendSysMessage(autore,"ATTENZIONE: PRESTARE MOLTA ATTENZIONE ALLA SINTASSI PER EVITARE CRASHES , IL PROCESSO PUO' CAUSARE MOLTA LAG");
                if (!stringa || !strcmp(stringa," ")) 
                { 
                    sHw2->Hw2SendSysMessage(autore,"massive_pdump carica/scrivi");
                    sHw2->Hw2SendSysMessage(autore,"sintassi <carica>: massive_pdump carica [AccId](account da cui partire a caricare) [Directory] (directory dei files)");
                    sHw2->Hw2SendSysMessage(autore,"sintassi <scrivi>: massive_pdump scrivi [Directory] (directory nel quale scrivere tutti i dumps)");
                    sHw2->Hw2SendSysMessage(autore,"*N.B.  non inserire lo slash / alla fine della directory , se specificata. Es : (non corretto)dump/   (corretto) dump ");
                    return false; 
                }    

                std::string scelta = strtok(stringa, " ");              // crea il token per la strtok successiva
                std::string argomento = strtok(NULL, ""); 

                if (!scelta.empty())
                    if (scelta=="carica")
                        sHw2->AzDumpLoad(autore,argomento.c_str());
                    else if (scelta=="scrivi")
                        sHw2->AzDumpWrite(autore,argomento.c_str());
                    else return false;

                return true;

            }


         }
	
        sHw2->Hw2SendSysMessage(autore,"Comando errato o non inserito o non si hanno i permessi per accedere al comando, digita .az comandi per visualizzare i comandi disponibili");

        return false;
    }
};

void AddSC_hw2system_commandscript()
{
    new hw2system_commandscript();
}

#endif