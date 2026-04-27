set(c=CMAKE_TOOLCHAIN_FILE ./single_hand_controller/cmake/ArduinoToolchain.cmake)
generate_arduino_firmware(single_hand_controller_v1
    BOARD m2560
    SKETCH ./single_hand_controller
    HDRS ./single_hand_controller/include/*
    LIBS TFT Arduino

)