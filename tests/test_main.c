
#include "tests_main.h"

int main(void) {
  int failed = 0;
  // в main suite хранится suite - набор тестов для отдельной функции
  Suite *main_suite[] = {tests_invalid_input(), tests_calculate(), NULL};
  SRunner *runner;
  // в runner происходит запуск набора тест-кейсов (suite)
  for (int i = 0; main_suite[i] != NULL; i++) {
    runner = srunner_create(main_suite[i]);
    // srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  if (failed != 0) {
    printf("========= FAILED: %d =========\n", failed);
  } else
    printf("========= TESTS PASSED SUCCES =========\n");
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
