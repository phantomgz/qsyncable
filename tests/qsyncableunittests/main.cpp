#include <QString>
#include <QtTest>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>
#include "testrunner.h"
#include "qsyncabletests.h"
#include "benchmarktests.h"


void handleBacktrace(int sig) {
  void *array[100];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 100);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}


int main(int argc, char* argv[]) {
    signal(SIGSEGV, handleBacktrace);

    QGuiApplication app(argc, argv);
    TestRunner runner;

    runner.add<QSyncableTests>();
    runner.add(QString(SRCDIR));
    runner.add<BenchmarkTests>();

    bool error = runner.exec(app.arguments());

    if (!error) {
        qDebug() << "All test cases passed!";
    }

    return error;
}