#include "ScriptPCH.h"

#define PVALOR_CURRENCY 396 // Valor de currency Puntos de Valor
#define PVALOR_10N_CANTIDAD 7500 // Cantidad de puntos de valor 10 normal
#define PVALOR_25N_CANTIDAD 8000 // Cantidad de puntos de valor 25 normal
#define PVALOR_10H_CANTIDAD 10000 // Cantidad de puntos de valor 10 Hero
#define PVALOR_25H_CANTIDAD 11000 // Cantidad de puntos de valor 25 Hero

enum  BOSSES
{
	RAGNAROS_10N	= 52409,
	RAGNAROS_25N	= 53797,
	RAGNAROS_10H	= 53798,
	RAGNAROS_25H 	= 53799,
	MAYORDOMO_10N 	= 52571,
	MAYORDOMO_25N 	= 53856,
	MAYORDOMO_10H 	= 53857,
	MAYORDOMO_25H 	= 53858,
	SHANNOX_10N		= 53691,
	SHANNOX_25N		= 53979,
	SHANNOX_10H		= 54079,
	SHANNOX_25H		= 54080,
	BALEROC_10N		= 53494,
	BALEROC_25N		= 53587,
	BALEROC_10H		= 53588,
	BALEROC_25H		= 53589,
	BETHTILAC_10N	= 52498, 
	BETHTILAC_25N	= 53576,
	BETHTILAC_10H	= 53577,
	BETHTILAC_25H	= 53578,
	ALYSRAZOR_10N 	= 52530,
	ALYSRAZOR_25N	= 54044,
	ALYSRAZOR_10H	= 54045,
	ALYSRAZOR_25H	= 54046,
	PIROCLASTO_10N 	= 52558,
	PIROCLASTO_25N 	= 52559,
	PIROCLASTO_10H	= 52560,
	PIROCLASTO_25H	= 52561
};

class sistema_pve : public PlayerScript
{
  public:
    sistema_pve() : PlayerScript("sistema_pve") { }

  void OnCreatureKill(Player * killer, Creature* killed)
  {
	switch(killed->GetEntry())
    {
			//RAGNAROS - FIRELANDS
            case RAGNAROS_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case RAGNAROS_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case RAGNAROS_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case RAGNAROS_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
            // MAYORDOMO - FIRELANDS
			 case MAYORDOMO_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case MAYORDOMO_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case MAYORDOMO_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case MAYORDOMO_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
			// SHANNOX - FIRELANDS
			 case SHANNOX_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case SHANNOX_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case SHANNOX_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case SHANNOX_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
			// BALEROC - FIRELANDS
			 case BALEROC_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case BALEROC_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case BALEROC_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case BALEROC_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
			// BETHTILAC - FIRELANDS
			 case BETHTILAC_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case BETHTILAC_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case BETHTILAC_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case BETHTILAC_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
			// ALYSRAZOR - FIRELANDS
			 case ALYSRAZOR_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case ALYSRAZOR_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case ALYSRAZOR_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case ALYSRAZOR_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
			// PIROCLASTO - FIRELANDS
             case PIROCLASTO_10N: 
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10N_CANTIDAD);
                break;
            case PIROCLASTO_25N:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25N_CANTIDAD);
                break;
            case PIROCLASTO_10H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_10H_CANTIDAD);
                break;
            case PIROCLASTO_25H:
                killer->ModifyCurrency(PVALOR_CURRENCY, PVALOR_25H_CANTIDAD);
                break;
            
            //Asi para cada boss
            default: // Al matar otra creatura simplemente rompe el ciclo
            break;
     }
  }
};




void AddSC_sistema_pve()
{
new sistema_pve();
}
