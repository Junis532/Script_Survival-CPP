// item.h
#pragma once
#include "inout.h"
#include "utils.h"

typedef struct player player_t;

// ==================== 아이템 관련 상수 정의 ====================
#define NORMAL_ITEM_COUNT 24
#define RARE_ITEM_COUNT 18
#define EPIC_ITEM_COUNT 12
#define UNIQUE_ITEM_COUNT 6

#define ITEMS_PER_PAGE 6
#define ITEMS_PER_ROW 3

#define RARITY_COUNT 4

#define SET_EFFECT_COUNT 6

extern const int rarity_item_counts[RARITY_COUNT];
// =============================================================

#define EQUIPMENTS_COUNT 60

#define ITEM_COUNT 24

#define HEAL_ITEM_COUNT 6

#define BUFFER_SIZE 1024

enum item_type_t {
    ITEM_TYPE_WEAPON,
    ITEM_TYPE_ARMOR,
    ITEM_TYPE_HEAL_ITEM
};

// 장비 등급 (일반, 희귀, 영웅, 유니크)
enum equipment_rarity_t {
    RARITY_NORMAL = 0,
    RARITY_RARE,
    RARITY_EPIC,
    RARITY_UNIQUE,
};

enum set_effect_list_t {
    SET_EFFECT_INVALID = -1,   // 유효하지 않은 ID
    SET_EFFECT_NONE = 0,   // [이름 없는]
    SET_EFFECT_DRAGON_SLAYER,  // [용살자]
    SET_EFFECT_NIGHT_SHADOW,   // [밤그림자]
    SET_EFFECT_STARLIGHT_GUIDE,// [별빛 인도자]
    SET_EFFECT_DESTROYER,      // [파괴자]
    SET_EFFECT_BERSERKER,      // [광전사]
};

extern char rarity_name[RARITY_COUNT];

// 장비 구조체
struct equipment_t {
    char name[64];
    char description[256];

    equipment_rarity_t rarity;

    // 공통 능력치
    int attack_bonus;
    int max_hp_bonus;
    int speed_bonus;
    double evasion_bonus;
    double defence_bonus;

    // 무기 전용 능력치
    double crit_chance_bonus;
    double crit_damage_bonus;
    int break_extra_damage_bonus;

    int buy_price;
    int sell_price;

    int id; // 아이템 고유 ID
};


// 소비 아이템 구조체
struct heal_item_t {
    char name[64];
    char description[256]; 

    int hp_bonus;

    int buy_price;  
    int sell_price; 
};  

// 세트 효과 구조체
struct set_effect_t {
    char name[64];
	char description[256];

    int id;
};

extern equipment_t temp_weapons[EQUIPMENTS_COUNT];
extern equipment_t temp_armors[EQUIPMENTS_COUNT];
extern equipment_t weapons[RARITY_COUNT][ITEM_COUNT];
extern equipment_t armors[RARITY_COUNT][ITEM_COUNT];

extern heal_item_t heal_items[HEAL_ITEM_COUNT];

extern set_effect_t set_effects[SET_EFFECT_COUNT];


class Item
{
public:
    Item();
    ~Item();

    void item_init(void);

    void use_weapon(equipment_rarity_t rarity, int next_index, player_t* player);
    void use_armor(equipment_rarity_t rarity, int next_index, player_t* player);
    bool use_heal_item(int item_index, player_t* player);

    void apply_set_effects(player_t* player, int selected_index);

    void remove_set_effects(player_t* player);

};

extern Item item;