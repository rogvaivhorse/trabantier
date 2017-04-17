/*
 * tester.h
 *
 * Created: 15/06/2016 02:41:53
 *  Author: Suburban
 */ 


#ifndef TESTER_H_
#define TESTER_H_

//m_state =  0 ==> sequential XYYZ test
//m_state = 16 ==> full XYZ test (x1 and y1 retarded by -100)
//m_state = 10 ==> only X test
//m_state =  6 ==> full YY test
//m_state = 14 ==> only top Y test
//m_state = 12 ==> only bottom Y test (y1 retarded by -100)
//m_state =  8 ==> only Z test

//m_state = 18 ==> new only top Y test
//m_state = 20 ==> new only X test

uint32_t tester_test_static (uint32_t, uint32_t);
void tester_test_setpoint (void);

#endif /* TESTER_H_ */