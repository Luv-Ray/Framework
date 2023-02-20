public class Test {
	// 定义一个成员数组保存有效用户的信息：
	String[] userDB = { "admin^123", "liu^456", "ascent^789" };

	// 定义一个login()方法对用户登陆进行有效性检查：
	public void login(String username, String password) {
		int i = 0;
		while (i < userDB.length) {
			byte[] b = userDB[i].getBytes();
			String u = "";
			String p = "";
			int j = 0;
			while (j < b.length) {
				if ('^' == b[j]) {
					u = userDB[i].substring(0, j);
					p = userDB[i].substring(j + 1, userDB[i].length());
					break;
				}
				j++;
			}
			if (u.equals(username) && p.equals(password)) {
				System.out.println("用户登录成功！");
				return;
			} else {
				if (i == userDB.length - 1) {
					System.out.println("用户名或密码错误！");
				}
			}
			i++;
		}
	}

	// 定义main()方法，定义两个变量作为要登录的用户信息并进行测试：
	public static void main(String[] args) {

		String username = "admin_error";
		String password = "123";
		Test l = new Test();
		l.login(username, password);

	}

}
