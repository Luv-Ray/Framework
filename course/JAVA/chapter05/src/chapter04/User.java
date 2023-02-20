package chapter04;

class Product implements java.lang.Comparable, java.io.Serializable {
	private String productname; // 药品名称
	private String cas; // 化学文摘登记号
	private String structure; // 结构图名称
	private String formula; // 化学式
	private String price; // 价格
	private String realstock; // 数量
	private String category; // 类别
	// 构造

	public Product() {
	}

	public Product(String productName, String cas, String structure, String formula, String price, String realstock,
			String category) {
		this.productname = productName;
		this.structure = structure;
		this.formula = formula;
		this.price = price;
		this.realstock = realstock;
		this.cas = cas;
		this.category = category;
	}

	// 各类get set方法
	public String getCas() {
		return cas;
	}

	public void setCas(String cas) {
		this.cas = cas;
	}

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}

	public String getFormula() {
		return formula;
	}

	public void setFormula(String formula) {
		this.formula = formula;
	}

	public String getPrice() {
		return price;
	}

	public void setPrice(String price) {
		this.price = price;
	}

	public String getProductname() {
		return productname;
	}

	public void setProductname(String productname) {
		this.productname = productname;
	}

	public String getRealstock() {
		return realstock;
	}

	public void setRealstock(String realstock) {
		this.realstock = realstock;
	}

	public String getStructure() {
		return structure;
	}

	public void setStructure(String structure) {
		this.structure = structure;
	}

	// 重写toString
	@Override
	public String toString() {
		return "Productname:" + this.getProductname() + " CAS:" + this.getCas() + " Structure:" + this.getStructure()
				+ " Formula:" + this.getFormula() + " Price:" + this.getPrice() + " Realstock:" + this.getRealstock()
				+ " Category:" + this.getCategory();
	}

	public int compareTo(Object o) {
		Product product = (Product) o;
		return this.getProductname().compareTo(product.getProductname());
	}
}

public class User implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
	private String username; // 用户名
	private String password; // 密码
	private int authority; // 用户权限
	// 构造

	public User() {
	}

	public User(String username, String password) {
		this.username = username;
		this.password = password;
	}

	public User(String username, String password, int authority) {
		this.username = username;
		this.password = password;
		this.authority = authority;
	}

	// 各类set get方法
	public int getAuthority() {
		return authority;
	}

	public void setAuthority(int authority) {
		this.authority = authority;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	// 重写toString
	@Override
	public String toString() {
		return this.getUsername() + "  " + this.getPassword();
	}

	public static void main(String[] args) // test
	{
		User user = new User();
		user.setUsername("admin");
		user.setPassword("123");
		User user1 = new User("ascent", "456");
		System.out.println("--输出get方法:");
		System.out.println(user.getUsername());
		System.out.println(user.getPassword());
		System.out.println(user1.getUsername());
		System.out.println(user1.getPassword());

		Product P = new Product();
		P.setProductname("布洛芬缓释胶囊"); // 药品名称
		P.setCas("15687-27-1"); // 化学文摘登记号
		P.setStructure(""); // 结构图名称
		P.setFormula("C13H18O2"); // 化学式
		P.setPrice("8.04元/盒"); // 价格
		P.setRealstock("30粒/盒，每粒0.3g"); // 数量
		P.setCategory("止痛药"); // 类别
		System.out.println("--输出get方法:");
		System.out.println(P.getProductname());
		System.out.println("--重写toString类输出:");
		System.out.println(user);
		System.out.println(P);
	}
}
