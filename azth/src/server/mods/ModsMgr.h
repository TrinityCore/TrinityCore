#ifndef MODSMGR_H
#define	MODSMGR_H

class ModsMgr {
private:
    ModsMgr();
    ~ModsMgr();
public: /* singleton init */

    static ModsMgr* instance() {
        static ModsMgr instance;
        return &instance;
    }

    void Initialization();
};

#define sModsMgr ModsMgr::instance()

#endif	/* MODSMGR_H */

