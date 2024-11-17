import numpy as np

def calculate_inverse_matrix():
    try:
        # 读取矩阵维度
        n = int(input("请输入矩阵的维度 n："))

        # 读取矩阵元素
        print(f"请输入 {n}x{n} 矩阵的元素（每行用空格分隔）：")
        matrix = []
        for i in range(n):
            # 读取每行的元素并转换为浮点数
            row = list(map(float, input().split()))
            if len(row) != n:
                raise ValueError("输入的元素数量不正确")
            matrix.append(row)

        # 转换为 NumPy 数组
        matrix = np.array(matrix)

        # 计算行列式，检查矩阵是否可逆
        det = np.linalg.det(matrix)
        if abs(det) < 1e-10:  # 考虑浮点数精度问题
            print("矩阵不可逆")
            return

        # 计算逆矩阵
        inverse_matrix = np.linalg.inv(matrix)

        # 输出结果，保留4位小数
        print("\n逆矩阵为：")
        for row in inverse_matrix:
            # 格式化输出每个元素
            print(" ".join([f"{x:8.4f}" for x in row]))

    except ValueError as e:
        print(f"输入错误：{str(e)}")
    except Exception as e:
        print(f"计算过程中出现错误：{str(e)}")


if __name__ == "__main__":
    calculate_inverse_matrix()