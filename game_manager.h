// game_manager.h
#pragma once
#include "player.h"
#include "monster.h"
#include "UI_info.h"

// 게임의 모든 데이터와 상태를 담는 통합 구조체
struct game_context_t {
    // --- 핵심 데이터 ---
    player_t player;
    monster_t monster;
    game_mode_state_t game_mode;
    int currentStage;
    hero_t choice_hero;

    // --- UI 상태 ---
    UI_state_t ui_main_state;
    title_state_t ui_title_state;
    setting_state_t ui_setting_state;
    game_mode_state_t ui_mode_state;
    player_action_state_t player_action_state;
	esc_menu_state_t ui_esc_menu_state;
	save_load_num_t save_load_num;
	new_or_load_game_t new_or_load_game;
	heal_or_store_t heal_or_store_state;
    int upgrade_selection;
    bool is_change_ui_main;

    // --- 시스템 설정 ---
    bool is_normal_mode_cleared;
    int global_volume;

    int field_action_value;
    int field_speed;
    int field_type;
    int field_turn;
	bool is_field_effect_on;
};

class GameManager
{
private:
    static GameManager* instance; // 싱글톤 인스턴스
    GameManager();                // private 생성자

    // 복사 금지
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

public:
    ~GameManager() {}

    game_context_t context;       // 게임 상태는 멤버로 유지

    static GameManager* GetInstance();

    void Init();
    void Run();
    void Shutdown();
};
