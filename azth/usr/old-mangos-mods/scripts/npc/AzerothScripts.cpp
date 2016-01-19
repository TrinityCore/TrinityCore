#include "precompiled.h"
#include "../../../../game/ZZ_ScriptsPersonali.h"

uint32 paga = 10000000;
Creature *Pet;
uint32 itemset;
uint32 level;
uint32 spawntime = 80000;
uint16 dist = 1;
float x = 0, y = 0, z = 0;

//INIZIALIZZAZIONE LISTE CONCATENATE
typedef struct sm {
	Creature *c_summon;
	ObjectGuid c_guid;
	ObjectGuid owner;
	char type;
	struct sm *next;
} summon;

int dlstore(Creature *crt, ObjectGuid owner, char type, struct sm **start) {

	struct sm *n = (struct sm *) malloc(sizeof(struct sm));
	if (!n)
		return -1; /* Out of Memory */

	n->c_summon = crt;
	n->c_guid = crt->GetObjectGuid();
	n->owner = owner;
	n->type = type;

	if (*start == NULL) { /* vuoto */
		*start = n;
		n->next = NULL;
	} else { /* non vuoto */
		n->next = *start;
		*start = n;
	}

	return 0; /* allocazione riuscita */
}

struct sm *dlsearch(uint64 owner, char type, struct sm **start) {

	struct sm *n = *start;

	while (n) {
		if (n->owner == owner && n->type == type)
			return n; /* match */
		n = n->next;
	}

	return NULL; /* no match */
}

int dldelete(uint64 owner, char type, struct sm **start) {

	struct sm *n = *start;
	struct sm *p = n;

	/* match all'inizio */
	if (n && (n->owner == owner && n->type == type)) {
		if (n->next)
			*start = n->next;
		else
			*start = NULL;
		free(n);

		return 0;
	}

	while (n) {
		if (n->owner == owner && n->type == type) { /* trovato */
			p->next = n->next;
			free(n);

			return 0;
		} else { /* prossimo */
			p = n;
			n = n->next;
		}
	}

	return -1; /* niente da cancellare */
}

//
//  ITEM PER AZEROTH
//

/* Inizializza il riferimento di inizio lista a NULL */
struct sm *list_head = NULL;

bool ItemUse_Azeroth_Item(Player *player, Item* _Item,
		SpellCastTargets const& targets) {

	struct sm *current_summon = dlsearch(player->GetObjectGuid(), 0,
			&list_head);

	Unit *fake = NULL;
	Creature *tmp = NULL;

	if (!current_summon) { // non trovato
		player->GetClosePoint(x, y, z, player->GetObjectBoundingRadius());
		tmp = player->SummonCreature(AZEROTH_AIUTANTE, x, y, z, 4.14,
				TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spawntime);
		dlstore(tmp, player->GetObjectGuid(), 0, &list_head);

	} else { //se lo ha trovato cancelliamo lo spawn dal mondo se c'e' ancora e ne aggiungiamo uno nuovo
		fake = ObjectAccessor::GetUnit(*current_summon->c_summon,
				current_summon->c_guid);

		if (fake && fake->isAlive()) {
			fake->SetVisibility(VISIBILITY_OFF);
			fake->DealDamage(fake, fake->GetHealth(), NULL, DIRECT_DAMAGE,
					SPELL_SCHOOL_MASK_NORMAL, NULL, false);

		}
		dldelete(player->GetObjectGuid(), 0, &list_head);
		player->GetClosePoint(x, y, z, player->GetObjectBoundingRadius());
		tmp = player->SummonCreature(AZEROTH_AIUTANTE, x, y, z, 4.14,
				TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spawntime);
		dlstore(tmp, player->GetObjectGuid(), 0, &list_head);

	}

	fake = NULL;
	fake = ObjectAccessor::GetUnit(*tmp, tmp->GetObjectGuid());
	if (fake && fake->isAlive())
		fake->addUnitState(UNIT_STAT_ROOT);

	return false;
}

//
//  AZEROTH NPC TOURNAMENT
// 

bool GossipHello_Azeroth_tournament(Player *player, Creature *_Creature) {
	switch (player->getClass()) {
	case CLASS_PALADIN:
		player->ADD_GOSSIP_ITEM( 7, "Holy PvP Set", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM( 7, "Protection PvP Set", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM( 7, "Retribution PvP Set", GOSSIP_SENDER_MAIN, 5);
		break;
	case CLASS_PRIEST:
		player->ADD_GOSSIP_ITEM( 7, "Discipline/Holy PvP Set", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM( 7, "Discipline/Shadow PvP set", GOSSIP_SENDER_MAIN, 4);
		break;
	case CLASS_SHAMAN:
		player->ADD_GOSSIP_ITEM( 7, "Enhancement PvP Set", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM( 7, "Elemental PvP Set", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM( 7, "Restoration PvP Set", GOSSIP_SENDER_MAIN, 5);
		break;
	case CLASS_WARLOCK:
		player->ADD_GOSSIP_ITEM( 7, "Demonology/Affliction PvP Set", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM( 7, "Demonology/Destruction PvP Set", GOSSIP_SENDER_MAIN, 4);
		break;
	case CLASS_DRUID:
		player->ADD_GOSSIP_ITEM( 7, "Feral PvP Set", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM( 7, "Balance PvP Set", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM( 7, "Restoration PvP Set", GOSSIP_SENDER_MAIN, 5);
		break;
	default:
		player->ADD_GOSSIP_ITEM( 7, "PVP Set", GOSSIP_SENDER_MAIN, 3);
		break;
	}

	player->ADD_GOSSIP_ITEM( 7, "Richiama il trainer - Summon your trainer ", GOSSIP_SENDER_MAIN, 6);
	player->ADD_GOSSIP_ITEM( 7, "General Goods", GOSSIP_SENDER_MAIN, 7);
	player->ADD_GOSSIP_ITEM( 7, "Ripara tutto - Repair all", GOSSIP_SENDER_MAIN, 8);
	player->ADD_GOSSIP_ITEM( 7, "Rifornimento denaro - Money Supply", GOSSIP_SENDER_MAIN, 9);

	if (player->getClass() == CLASS_HUNTER)
		player->ADD_GOSSIP_ITEM( 7, "Pets", GOSSIP_SENDER_MAIN, 10);
	if (player->getClass() == CLASS_HUNTER
			|| player->getClass() == CLASS_WARLOCK)
		player->ADD_GOSSIP_ITEM( 7, "Pet Trainer", GOSSIP_SENDER_MAIN, 11);
// player->ADD_GOSSIP_ITEM( 7, "Mostrami la banca", GOSSIP_SENDER_MAIN, 30);

	player->ADD_GOSSIP_ITEM( 7, "Cambia Zona  - Change Zone", GOSSIP_SENDER_MAIN, 12);
	player->ADD_GOSSIP_ITEM( 7, "Converti i tuoi crediti in punti Arena   -Convert your credits in Arena points", GOSSIP_SENDER_MAIN, 13);
	player->ADD_GOSSIP_ITEM( 7, "Mostra i Premi - Show Awards", GOSSIP_SENDER_MAIN, 14);
	player->ADD_GOSSIP_ITEM( 7, "* Per le info del DeathMatch digita < .az profilo > in chat -- For info about the DeathMatch.. type < .az profilo > in the chat", GOSSIP_SENDER_MAIN, 15);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
// _Creature->Say(HELLO, LANG_UNIVERSAL, NULL);  benvenuto
	_Creature->HandleEmoteCommand(EMOTE_ONESHOT_BOW);

	return true;

}

void SendDefaultMenu_Azeroth_tournament(Player *player, Creature *_Creature,
		uint32 action) {

	uint32 trainerid;
	Unit *fake1 = NULL;
	Unit *fake2 = NULL;
	Creature *tmp = NULL;
	Hw2Class *hw2 = new Hw2Class;

	player->CLOSE_GOSSIP_MENU();

	if (player->isInCombat()) {
		_Creature->MonsterSay(
				"Sei in combat, sconfiggi prima i tuoi nemici! || You are in combat! Fight your battle!",
				LANG_UNIVERSAL, NULL);
		return;
	}

	level = player->getLevel();

//_Creature->CastSpell(player, SPELL_TELEEFFECT2, true);

//ricerca nella lista
	struct sm *current_trainer = dlsearch(player->GetObjectGuid(), 1,
			&list_head);
	struct sm *current_pet_trainer = dlsearch(player->GetObjectGuid(), 2,
			&list_head);

	switch (action) {

	// SET PVP 1
	case 3:
		itemset = 0;
		switch (player->getClass()) {
		case CLASS_WARRIOR:
			itemset = 16;
			break;
		case CLASS_PALADIN:
			itemset = 17;
			break;
		case CLASS_HUNTER:
			itemset = 20;
			break;
		case CLASS_ROGUE:
			itemset = 21;
			break;
		case CLASS_PRIEST:
			itemset = 22;
			break;
		case CLASS_DEATH_KNIGHT:
			itemset = 60;
			break; //classe mancante
		case CLASS_SHAMAN:
			itemset = 24;
			break;
		case CLASS_MAGE:
			itemset = 27;
			break;
		case CLASS_WARLOCK:
			itemset = 28;
			break;
		case CLASS_DRUID:
			itemset = 30;
			break;
		default:
			return;
			break;
		}
		hw2->DmAddItemSet(player, itemset);

		break;

		// SET PVP 2
	case 4:
		itemset = 0;
		switch (player->getClass()) {
		case CLASS_PALADIN:
			itemset = 18;
			break;
		case CLASS_PRIEST:
			itemset = 23;
			break;
		case CLASS_SHAMAN:
			itemset = 25;
			break;
		case CLASS_WARLOCK:
			itemset = 29;
			break;
		case CLASS_DRUID:
			itemset = 31;
			break;
		default:
			return;
			break;
		}
		hw2->DmAddItemSet(player, itemset);
		;
		break;

		// SET PVP 3
	case 5:
		itemset = 0;
		switch (player->getClass()) {
		case CLASS_PALADIN:
			itemset = 19;
			break;
		case CLASS_SHAMAN:
			itemset = 26;
			break;
		case CLASS_DRUID:
			itemset = 32;
			break;
		default:
			return;
			break;
		}
		hw2->DmAddItemSet(player, itemset);
		break;

		//  trainers
	case 6:
		trainerid = 0;
		if (player->GetTeam() == ALLIANCE) {
			switch (player->getClass()) {
			case CLASS_WARRIOR:
				trainerid = 914;
				break;
			case CLASS_PALADIN:
				trainerid = 928;
				break;
			case CLASS_HUNTER:
				trainerid = 5115;
				break;
			case CLASS_ROGUE:
				trainerid = 13283;
				break;
			case CLASS_PRIEST:
				trainerid = 376;
				break;
			case CLASS_SHAMAN:
				trainerid = 17204;
				break;
			case CLASS_MAGE:
				trainerid = 5146;
				break;
			case CLASS_WARLOCK:
				trainerid = 461;
				break;
			case CLASS_DRUID:
				trainerid = 4217;
				break;
			default:
				return;
			}
		} else if (player->GetTeam() == HORDE) {
			switch (player->getClass()) {
			case CLASS_WARRIOR:
				trainerid = 3353;
				break;
			case CLASS_PALADIN:
				trainerid = 16681;
				break;
			case CLASS_HUNTER:
				trainerid = 3039;
				break;
			case CLASS_ROGUE:
				trainerid = 4584;
				break;
			case CLASS_PRIEST:
				trainerid = 4606;
				break;
			case CLASS_SHAMAN:
				trainerid = 3344;
				break;
			case CLASS_MAGE:
				trainerid = 16653;
				break;
			case CLASS_WARLOCK:
				trainerid = 4563;
				break;
			case CLASS_DRUID:
				trainerid = 3034;
				break;
			default:
				return;
			}
		}

		if (trainerid == 0)
			return; //evita il crash

		if (!current_trainer) { // non trovato
			player->GetClosePoint(x, y, z, player->GetObjectBoundingRadius());
			tmp = player->SummonCreature(trainerid, x, y, z, 4.14,
					TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spawntime);
			dlstore(tmp, player->GetObjectGuid(), 1, &list_head);

		} else { //se lo ha trovato cancelliamo lo spawn dal mondo se c'e' ancora e ne aggiungiamo uno nuovo
			fake1 = ObjectAccessor::GetUnit(*current_trainer->c_summon,
					current_trainer->c_guid);
			if (fake1 && fake1->isAlive()) {
				fake1->SetVisibility(VISIBILITY_OFF);
				fake1->DealDamage(fake1, fake1->GetHealth(), NULL,
						DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
			}
			dldelete(player->GetObjectGuid(), 0, &list_head);
			player->GetClosePoint(x, y, z, player->GetObjectBoundingRadius());
			tmp = player->SummonCreature(trainerid, x, y, z, 4.14,
					TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spawntime);
			dlstore(tmp, player->GetObjectGuid(), 1, &list_head);

		}
		if (!tmp)
			return;
		fake1 = NULL;
		fake1 = ObjectAccessor::GetUnit(*tmp, tmp->GetObjectGuid());
		if (fake1 && fake1->isAlive()) {
			fake1->setFaction(35);
			fake1->addUnitState(UNIT_STAT_ROOT);
		}

		break;

	case 7:
		player->ADD_GOSSIP_ITEM( 7, "Meta Gems", GOSSIP_SENDER_MAIN, 20);
		player->ADD_GOSSIP_ITEM( 7, "Orange Gems", GOSSIP_SENDER_MAIN, 21);
		player->ADD_GOSSIP_ITEM( 7, "Green Gems", GOSSIP_SENDER_MAIN, 22);
		player->ADD_GOSSIP_ITEM( 7, "Purple Gems", GOSSIP_SENDER_MAIN, 23);
		player->ADD_GOSSIP_ITEM( 7, "Shaman Totems", GOSSIP_SENDER_MAIN, 24);
		player->ADD_GOSSIP_ITEM( 7, "Two Handed Weapons", GOSSIP_SENDER_MAIN, 25);
		player->ADD_GOSSIP_ITEM( 7, "One Handed Weapons", GOSSIP_SENDER_MAIN, 26);
		player->ADD_GOSSIP_ITEM( 7, "Ranged weapons", GOSSIP_SENDER_MAIN, 27);
		player->ADD_GOSSIP_ITEM( 7, "Shields", GOSSIP_SENDER_MAIN, 28);
		player->ADD_GOSSIP_ITEM( 7, "Idols Librams and Totems", GOSSIP_SENDER_MAIN, 29);
		player->ADD_GOSSIP_ITEM( 7, "Restoration Pack", GOSSIP_SENDER_MAIN, 30);
		player->ADD_GOSSIP_ITEM( 7, "Poison", GOSSIP_SENDER_MAIN, 31);
		player->ADD_GOSSIP_ITEM( 7, "Ammo Pack", GOSSIP_SENDER_MAIN, 32);
		player->ADD_GOSSIP_ITEM( 7, "Reagent Pack", GOSSIP_SENDER_MAIN, 33);
		player->ADD_GOSSIP_ITEM( 7, "Recupero borse iniziali - Recovery Initial Bags ", GOSSIP_SENDER_MAIN, 34);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
		break;

		//ripara tutto
	case 8:
		// ripara tutto senza chiedere costi, 0 risparmio e guildbank non attiva
		player->DurabilityRepairAll(false, 0, false);
		break;

		//Rifornisce di soldi - questa funzione potrei farla ogni volta che richiamo la creatura
	case 9:
		if (player->GetMoney() < paga)
			player->ModifyMoney(paga); // aggiunge del 1k ori se hai meno di 1k ori
		break;

		// Pets
	case 10:
		player->ADD_GOSSIP_ITEM( 7, "Lupo            Wolf", GOSSIP_SENDER_MAIN, 40);
		player->ADD_GOSSIP_ITEM( 7, "Gatto           Cat", GOSSIP_SENDER_MAIN, 41);
		player->ADD_GOSSIP_ITEM( 7, "Orso            Bear", GOSSIP_SENDER_MAIN, 42);
		player->ADD_GOSSIP_ITEM( 7, "Gorilla", GOSSIP_SENDER_MAIN, 43);
		player->ADD_GOSSIP_ITEM( 7, "Ravager", GOSSIP_SENDER_MAIN, 44);
		player->ADD_GOSSIP_ITEM( 7, "Scorpio", GOSSIP_SENDER_MAIN, 45);
		player->ADD_GOSSIP_ITEM( 7, "Ragno           Spider", GOSSIP_SENDER_MAIN, 46);
		player->ADD_GOSSIP_ITEM( 7, "Falco            Hawk", GOSSIP_SENDER_MAIN, 47);
		player->ADD_GOSSIP_ITEM( 7, "Warp Stalker", GOSSIP_SENDER_MAIN, 48);
		player->ADD_GOSSIP_ITEM( 7, "Cinghiale       Boar", GOSSIP_SENDER_MAIN, 49);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
		break;

		//pets trainer
	case 11:
		trainerid = 0;
		switch (player->getClass()) {
		case CLASS_HUNTER: //pet trainer
			if (player->GetTeam() == ALLIANCE)
				trainerid = 10090;
			else if (player->GetTeam() == HORDE)
				trainerid = 10086;
			break;
		case CLASS_WARLOCK: // demon trainer
			if (player->GetTeam() == ALLIANCE)
				trainerid = 5520;
			else if (player->GetTeam() == HORDE)
				trainerid = 5815;
			break;
		}

		if (trainerid == 0)
			return; //evita il crash

		if (!current_pet_trainer) { // non trovato
			player->GetClosePoint(x, y, z, player->GetObjectBoundingRadius());
			tmp = player->SummonCreature(trainerid, x, y, z, PET_FOLLOW_ANGLE,
					TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spawntime);
			dlstore(tmp, player->GetObjectGuid(), 2, &list_head);
		} else { //se lo ha trovato cancelliamo lo spawn dal mondo se c'e' ancora e ne aggiungiamo uno nuovo
			fake2 = ObjectAccessor::GetUnit(*current_pet_trainer->c_summon,
					current_pet_trainer->c_guid);
			if (fake2 && fake2->isAlive()) {
				fake2->SetVisibility(VISIBILITY_OFF);
				fake2->DealDamage(fake2, fake2->GetHealth(), NULL,
						DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
			}
			dldelete(player->GetObjectGuid(), 0, &list_head);
			tmp = player->SummonCreature(trainerid, x, y, z, PET_FOLLOW_ANGLE,
					TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spawntime);
			dlstore(tmp, player->GetObjectGuid(), 2, &list_head);

		}
		if (!tmp)
			return;
		fake2 = NULL;
		fake2 = ObjectAccessor::GetUnit(*tmp, tmp->GetObjectGuid());
		if (fake2 && fake2->isAlive()) {
			fake2->addUnitState(UNIT_STAT_ROOT);
			fake2->setFaction(35);
		}
		return;
		break;

	case 12:
		if (player->GetZoneId() != 616)
			player->ADD_GOSSIP_ITEM( 7, "Ritorna all'Hyjal     - Return to the Hyjal", GOSSIP_SENDER_MAIN, 60);
		if (player->GetAreaId() != 2317)
			player->ADD_GOSSIP_ITEM( 7, "Isole Tropicali       - Tropical Island", GOSSIP_SENDER_MAIN, 61);
		// [DISATTIVATO] if (player->GetMapId()!=44)   player->ADD_GOSSIP_ITEM( 7, "Monastero Sconosciuto - Unknown Monastery", GOSSIP_SENDER_MAIN, 62);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
		return;
		break;

	case 13:
		if (player->Crediti >= 50) {
			uint32 punti = player->Crediti * 3;
			player->ModifyArenaPoints(punti); // valido dalla 2.4.0
			player->Crediti = 0;
			player->GetSession()->SendNotification(
					"! Hai ricevuto %u punti Arena! - You received %u Arena Points",
					punti, punti);
			hw2->DmGestionePunti(player, true);
		} else
			_Creature->MonsterSay(
					"Devi avere almeno 50 crediti per poterli convertire! || You must have at least 50 credits to convert them!",
					LANG_UNIVERSAL, NULL);
		return;
		break;

	case 14:
		player->SEND_VENDORLIST( _Creature->GetObjectGuid() );
		return;
		break;

	case 15:
		return;
		break;

	}

	return;
}

void SendGeneralGoods_Menu(Player *player, Creature *_Creature, uint32 action) {
	player->CLOSE_GOSSIP_MENU();

	if (player->isInCombat()) {
		_Creature->MonsterSay(
				"Sei in combat, sconfiggi prima i tuoi nemici! -- You are in combat! Fight your battle!",
				LANG_UNIVERSAL, NULL);
		return;
	}

	Hw2Class *hw2 = new Hw2Class;
	itemset = 0;

	switch (action) {
	// gemme Meta Gems
	case 20:
		itemset = 10;
		break;
		// gemme Orange Gems
	case 21:
		itemset = 11;
		break;
		// gemme Green Gems
	case 22:
		itemset = 12;
		break;
		// gemme Purple Gems
	case 23:
		itemset = 13;
		break;
		// Shaman totems
	case 24:
		itemset = 15;
		break;
		// Two handed weapons
	case 25:
		itemset = 1;
		break;
		// One handed weapons
	case 26:
		itemset = 2;
		break;
		// Ranged weapons
	case 27:
		itemset = 3;
		break;
		// Shields
	case 28:
		itemset = 4;
		break;

		// Idols, Librams and Totems
	case 29:
		itemset = 5;
		break;
		// Restoration Pack
	case 30:
		itemset = 6;
		break;

		// Poison Pack
	case 31:
		itemset = 7;
		break;

		// Ammo Pack
	case 32:
		itemset = 8;
		break;

		// Reagent Pack
	case 33:
		itemset = 9;
		break;

	case 34:
		itemset = 35;
		break;
	}

	if (itemset == 0)
		return;

	hw2->DmAddItemSet(player, itemset);
}

void SendPets_Menu(Player *player, Creature *_Creature, uint32 action) {

	player->CLOSE_GOSSIP_MENU();

	if (player->isInCombat()) {
		_Creature->MonsterSay(
				"Sei in combat, sconfiggi prima i tuoi nemici! -- You are in combat! Fight your battle!",
				LANG_UNIVERSAL, NULL);
		return;
	}
	Hw2Class *hw2 = new Hw2Class;
	uint32 PetId = 0;

	switch (action) {
	case 40:
		PetId = 21956;
		break;
	case 41:
		PetId = 20671;
		break;
	case 42:
		PetId = 7445;
		break;
	case 43:
		PetId = 6585;
		break;
	case 44:
		PetId = 16934;
		break;
	case 45:
		PetId = 22100;
		break;
	case 46:
		PetId = 18467;
		break;
	case 47:
		PetId = 17129;
		break;
	case 48:
		PetId = 23219;
		break; //warp
	case 49:
		PetId = 16117;
		break; //chinghiale
	}
	if (PetId == 0)
		return;

	player->GetClosePoint(x, y, z, player->GetObjectBoundingRadius());
	Pet = _Creature->SummonCreature(PetId, x, y, z, PET_FOLLOW_ANGLE,
			TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 6000);
	hw2->DmCreaPet(player, Pet);

}

void SendTele_Menu(Player *player, Creature *_Creature, uint32 action) {

	player->CLOSE_GOSSIP_MENU();

	if (player->isInCombat()) {
		_Creature->MonsterSay(
				"Sei in combat, sconfiggi prima i tuoi nemici! -- You are in combat! Fight your battle!",
				LANG_UNIVERSAL, NULL);
		return;
	}
	Hw2Class *hw2 = new Hw2Class;
	switch (action) {
	//hyjal
	case 60:
		hw2->DmGestioneSpawning(player, 616);
		break;
		// isole
	case 61:
		hw2->DmGestioneSpawning(player, 2317);
		break;
		//monastero
	case 62:
		hw2->DmGestioneSpawning(player, 44);
		break;
	}
	return;
}

/*

 void MassimoReputazioni(Player *player)
 {
 uint8 idfazione[8]= { 946,934,935,942,989,1011,932,270}
 for (uint8 I=0;I<8;I++)
 if (player) player->ModifyOneFactionReputation(idfazione[I],44119)
 }
 */

bool GossipSelect_Azeroth_tournament(Player *player, Creature *_Creature,
		uint32 sender, uint32 action) {
// Main menu

	if (sender == GOSSIP_SENDER_MAIN) {
		if (action >= 20 && action < 40) {
			SendGeneralGoods_Menu(player, _Creature, action);
			return true;
		}
		if (action >= 40 && action < 60) {
			SendPets_Menu(player, _Creature, action);
			return true;
		}
		if (action >= 60) {
			SendTele_Menu(player, _Creature, action);
			return true;
		}
		SendDefaultMenu_Azeroth_tournament(player, _Creature, action);
		return true;
	}
	return false;

}

bool ReceiveEmote_Azeroth_tournament(Player *player, Creature *_Creature,
		uint32 emote) {
	_Creature->HandleEmoteCommand(emote);

	if (emote == EMOTE_ONESHOT_SALUTE)
		_Creature->MonsterSay("Onore e gloria soldato.", LANG_UNIVERSAL, NULL);

	return true;
}

bool GossipHello_Azeroth_vendors(Player *player, Creature *_Creature) {
// Main menu

	if (player->getLevel() < _Creature->getLevel()) //hack
			{
		_Creature->MonsterSay(
				"Non hai ancora il livello adatto - You don't have the level for it",
				LANG_UNIVERSAL, NULL);
		return false;
	} else {

		player->SEND_VENDORLIST( _Creature->GetObjectGuid() );
	}

	return true;

}

void AddSC_azeroth_scripts() {

	Script *newscript;

	newscript = new Script;
	newscript->Name = "Azeroth_item";
	newscript->pItemUse = ItemUse_Azeroth_Item;
	newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name = "Azeroth_tournament";
	newscript->pGossipHello = &GossipHello_Azeroth_tournament;
	newscript->pGossipSelect = &GossipSelect_Azeroth_tournament;
	//newscript->pReceiveEmote = &ReceiveEmote_Azeroth_tournament;
	newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name = "Azeroth_vendors";
	newscript->pGossipHello = &GossipHello_Azeroth_vendors;
	newscript->RegisterSelf();
}
