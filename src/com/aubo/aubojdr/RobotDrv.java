/**
 * 
 */
package com.aubo.aubojdr;

/**
 * 机械臂控制
 * @author zhao
 *
 */
public class RobotDrv {

	private int rshd;
	private native int initialize();
	private native int uninitialize();
	private native int createContext();
	private native int destoryContext(int rshd);
	private native int login(int rshd, String ip, int port);
	private native int logout(int rshd);
	private native int moveJ(int rshd, double[] waypoints);
	private native int moveL(int rshd, double[] waypoints);
	
	static {
		System.loadLibrary("aubojdr");
	}
	
	public RobotDrv() {
		this.rshd = -1;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("robot drv running...");
		RobotDrv robot = new RobotDrv();
		robot.initialize();
		int rshd = robot.createContext();
		robot.login(rshd, "127.0.0.1", 8899);
		robot.logout(rshd);
	}
}
