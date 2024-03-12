#include <stdio.h>
#include <math.h>

int UTA_ID = 1001845703; 
static double previous_theta_dot = 0;          // Static Variable to save the previou theta_dot value to 
static double rate = 500;        // Rate in Hz

double PD_control(theta, theta_dot, theta_ref, theta_dot_ref)
double theta, theta_dot, theta_ref, theta_dot_ref;
{
    double Torque = 0.555; // Torque value found by trial and error - which when returned the robot arm stops at any angle other than -pi/2
    printf("Theta = %lf\n", theta);

//-----------------------------------------------------------------Uncomment the following lines of code to calculate for gravity constant-----------------------------------------------------
//    double GravityConstant = Torque/cos(theta);  // Calculated gravity constant by dividing the constant torque by cosine(theta) 
//    printf("Gravity Constant = %lf\n", GravityConstant);
//    return(Torque);  // returning the constant torque to calculate for G (Gravity constant)
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    double G = 2.363021;  // Hardcoding the gravity constant
    double GravitationalForce = G * cos(theta);  // Calculating Gravitational Force


//-----------------------------------------------------------------Uncomment the following line of code if you want to check if your gravity constant is correct-------------------------------
//    return(GravitationalForce);      // The robot arm should be along the x axis  
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------Uncomment the following lines of code to calculate for viscous constant---------------------------------------------------------
//    double ViscousConstant = Torque / theta_dot;  // Calculated for viscous constant by dividing constant torque by theta_dot
//    printf("Viscous Const = %lf\n", ViscousConstant);
//    printf("Theta dot = %lf\n", theta_dot);
//    return(Torque + GravitationalForce);  // returnin constant torque + gravitational force, to compensate for gravity
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    double B = 0.709188;        // Hardcodiing for Viscous constant 
    double ViscousForce = B * theta_dot;        // Calculating Viscous Force


//    printf("Viscous Force = %lf\n", ViscousForce);
    double diff = theta_dot - previous_theta_dot;        // To calculate difference between current and previous theta_dot values
    printf("Previous theta dot = %lf\n", previous_theta_dot);         // Printing the previous theta_dot value
    printf("Theta dot = %lf\n", theta_dot);       // Printing the current theta_dot value
    printf("Diff = %lf\n", diff);            // Printing the calculated difference between current and previous theta_dot values
    previous_theta_dot = theta_dot;          // changing the previous theta dot value to the current value for the next iteration 
    double acceleration = diff * rate;            // Calculating acceleration or theta double dot value by multiplying the difference in theta_dot value with rate
    printf("Acceleration = %lf\n", acceleration);  // Printing Acceleration 

//---------------------------------------------------------------Uncomment the following line of code to check if viscous constant is correct---------------------------------------------------
//    return(ViscousForce + GravitationalForce);   // the robot arm should move with zero or almost negligible acceleration
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------Uncomment the following lines of code to calculate for inertia-----------------------------------------------------------------
    double InertiaConstant = Torque/acceleration;          // Inertia is Torque divided by acceleration (or theta_double_dot)
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Inertia Constant = %lf\n", InertiaConstant);
    
// Inertia constant is oscillating between values so with the highest limit being 0.051336

    double I = 0.051336;      // Hardcoding Inertia Constant 
    //printf("\n");

    printf("Parameters - \n");
    printf("G = %lf\nB = %lf\nI = %lf\n", G, B, I);
    return(Torque + ViscousForce + GravitationalForce);     // returning Sum of Constant torque + Viscous Force + Gravitational Force, to compensate for gravity and friction


// Part 2 - Extra Credit
// Control Force = I * (Kp(theta - theta_ref) + Kv(theta_dot)) + (B * theta_dot) + (G * cos(theta))

}






















