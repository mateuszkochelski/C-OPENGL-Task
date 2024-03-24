# CMakeList.txt: plik projektu CMake najwyższego poziomu, wykonaj konfigurację globalną
# i uwzględnij podprojekty w tym miejscu.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Włącz przeładowywanie kodu XAML na gorąco dla kompilatorów MSVC, jeśli jest to obsługiwane.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Automat")

# Uwzględnij podprojekty.

# Ścieżka do pliku źródłowego z ustawieniami
set(CONFIG_FILE_PATH "${CMAKE_SOURCE_DIR}/config/tickets.ini")

# Ścieżka docelowa, gdzie ma zostać skopiowany plik
set(CONFIG_DEST_PATH "${CMAKE_BINARY_DIR}/tickets.ini")

# Kopiowanie i dostosowanie pliku
configure_file(${CONFIG_FILE_PATH} ${CONFIG_DEST_PATH} COPYONLY)

add_executable(main "main.cpp" "State.h" "Machine.h" "takingMoneyState.h" "choosingTicketState.h" "PrintTicketState.h" "RefundMoneyState.h" "EndState.h" )
