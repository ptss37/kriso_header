#include <stdint.h>

typedef struct _ControllerToVcc {
    // 제어 명령
    float t1_rps; // 좌현 선수추진기 회전수, QGC
    float t2_rps; // 우현 선수추진기 회전수, QGC
    float t3_rps; // 좌현 메인추진기 회전수, QGC
    float t3_angle; // 좌현 메인추진기 각도, QGC
    float t4_rps;   // 우현 메인추진기 회전수, QGC
    float t4_angle; // 우현 메인추진기 각도, QGC
    float psi_d; // 추종 선수각
    float spd_d; // 추종 속도
    float wp_lat_d; // 추종 경유점 경도
    float Wp_lon_d; // 추종 경유점 위도
    uint32_t oper_Mode; // 현재 운용 모드
    // 충돌 회피
    uint32_t ca_mode; // 충돌회피 모드(Enable/Disable)
    uint32_t ca_method; // 충돌회피방법 (Reactive / Path plan)
    uint32_t ca_status; // 회피 상태 - 안전 / 충돌회피
    float ca_risk_arr[900]; // 충돌위험도 배열(1도 간격 180도, 5개 속도 후보)
    float reactive_spd_d; // 반응형 충돌회피 속도명령
    float reactive_psi_d; // 반응형 충돌회피 선수각명령
    // 경로 계획
    float track_path[200]; // 추종경로(회피경로/기존경로), 경유점 배열 100개
    uint32_t track_path_idx; // 충종 경유점 번호
    // Echo Back 신호
    uint8_t rx_signal[132]; // 통합운항제어로부터 수신 정보(132 Byte)
} ControllerToVcc;
