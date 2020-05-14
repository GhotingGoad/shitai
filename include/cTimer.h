#ifndef CTIMER_H
#define CTIMER_H

void startTimer();
void refreshTimer();
void restartTimer();
void stopTimer();

Uint32 restartTimer(Uint32 interval, void* param);
Uint32 moveDown(Uint32 interval, void* param);
Uint32 refreshTimer(Uint32 interval, void* param);


#endif // CTIMER_H
